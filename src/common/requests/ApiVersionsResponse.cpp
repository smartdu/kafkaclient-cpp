#include "ApiVersionsResponse.h"
#include "Schema.h"
#include "Field.h"
#include "ArrayOf.h"
#include "CommonFields.h"
#include "ApiKeys.h"
#include "Errors.h"
#include "RecordBatch.h"
#include "Struct.h"
#include "Integer.h"
#include "Short.h"
#include "ObjectArray.h"
#include "Arrays.h"

const char* ApiVersionsResponse::API_VERSIONS_KEY_NAME = "api_versions";
const char* ApiVersionsResponse::API_KEY_NAME = "api_key";
const char* ApiVersionsResponse::MIN_VERSION_KEY_NAME = "min_version";
const char* ApiVersionsResponse::MAX_VERSION_KEY_NAME = "max_version";

Schema* ApiVersionsResponse::API_VERSIONS_V0 = new Schema(3,
	new Field(API_KEY_NAME, Type::INT16(), "API key."),
	new Field(MIN_VERSION_KEY_NAME, Type::INT16(), "Minimum supported version."),
	new Field(MAX_VERSION_KEY_NAME, Type::INT16(), "Maximum supported version."));

Schema* ApiVersionsResponse::API_VERSIONS_RESPONSE_V0 = new Schema(2,
	CommonFields::ERROR_CODE,
	new Field(API_VERSIONS_KEY_NAME, new ArrayOf(API_VERSIONS_V0), "API versions supported by the broker."));

Schema* ApiVersionsResponse::API_VERSIONS_RESPONSE_V1 = new Schema(3,
	CommonFields::ERROR_CODE,
	new Field(API_VERSIONS_KEY_NAME, new ArrayOf(API_VERSIONS_V0), "API versions supported by the broker."),
	CommonFields::THROTTLE_TIME_MS);

Schema* ApiVersionsResponse::API_VERSIONS_RESPONSE_V2 = API_VERSIONS_RESPONSE_V1;

ApiVersionsResponse* ApiVersionsResponse::defaultApiVersionsResponse_ = NULL;

Schema** ApiVersionsResponse::schemaVersions()
{
	static Schema* schemas[] = { API_VERSIONS_RESPONSE_V0, API_VERSIONS_RESPONSE_V1, API_VERSIONS_RESPONSE_V2, NULL };
	return schemas;
}

ApiVersionsResponse::ApiVersionsResponse(Errors *error, std::list<ApiVersion> apiVersions)
{
	init(DEFAULT_THROTTLE_TIME, error, apiVersions);
}

ApiVersionsResponse::ApiVersionsResponse(int throttleTimeMs, Errors *error, std::list<ApiVersion> apiVersions)
{
	init(throttleTimeMs, error, apiVersions);
}

ApiVersionsResponse::ApiVersionsResponse(Struct *s)
{
	this->throttleTimeMs_ = *(s->getOrElse(CommonFields::THROTTLE_TIME_MS, DEFAULT_THROTTLE_TIME));
	this->error_ = Errors::forCode(*s->get(CommonFields::ERROR_CODE));
	std::list<ApiVersion> tempApiVersions;
	ObjectArray *oa = s->getArray(API_VERSIONS_KEY_NAME);
	for (int i = 0; i < *oa; i ++)
	{
		Struct *apiVersionStruct = (Struct*)((*oa)[i]);
		short apiKey = *apiVersionStruct->getShort(API_KEY_NAME);
		short minVersion = *apiVersionStruct->getShort(MIN_VERSION_KEY_NAME);
		short maxVersion = *apiVersionStruct->getShort(MAX_VERSION_KEY_NAME);
		tempApiVersions.push_back(ApiVersion(apiKey, minVersion, maxVersion));
	}
	this->apiKeyToApiVersion = buildApiKeyToApiVersion(tempApiVersions);

    delete s;
}

ApiVersionsResponse* ApiVersionsResponse::apiVersionsResponse(int throttleTimeMs, char maxMagic)
{
	if (maxMagic == RecordBatch::CURRENT_MAGIC_VALUE && throttleTimeMs == DEFAULT_THROTTLE_TIME)
	{
		return defaultApiVersionsResponse();
	}
	return createApiVersionsResponse(throttleTimeMs, maxMagic);
}

int ApiVersionsResponse::throttleTimeMs()
{
	return this->throttleTimeMs_;
}

std::list<ApiVersion> ApiVersionsResponse::apiVersions()
{
	std::list<ApiVersion> tmp;
	for (std::map<short, ApiVersion>::iterator iter = apiKeyToApiVersion.begin(); iter != apiKeyToApiVersion.end(); iter ++)
	{
		tmp.push_back(iter->second);
	}
	return tmp;
}

ApiVersion ApiVersionsResponse::apiVersion(short apiKey)
{
	return apiKeyToApiVersion[apiKey];
}

Errors* ApiVersionsResponse::error()
{
	return this->error_;
}

std::map<Errors*, int> ApiVersionsResponse::errorCounts()
{
	return AbstractResponse::errorCounts(error_);
}

ApiVersionsResponse* ApiVersionsResponse::parse(ByteBuffer *buffer, short version)
{
	return new ApiVersionsResponse(ApiKeys::API_VERSIONS()->parseResponse(version, buffer));
}

ApiVersionsResponse* ApiVersionsResponse::createApiVersionsResponse(int throttleTimeMs, char minMagic)
{
	std::list<ApiVersion> versionList;
	return new ApiVersionsResponse(throttleTimeMs, Errors::NONE, versionList);
}

ApiVersionsResponse* ApiVersionsResponse::defaultApiVersionsResponse()
{
	if (defaultApiVersionsResponse_ == NULL)
		defaultApiVersionsResponse_ = createApiVersionsResponse(DEFAULT_THROTTLE_TIME, RecordBatch::CURRENT_MAGIC_VALUE);
	return defaultApiVersionsResponse_;
}

bool ApiVersionsResponse::shouldClientThrottle(short version)
{
	return version >= 2;
}

Struct* ApiVersionsResponse::toStruct(short version)
{
	Struct *s = new Struct(ApiKeys::API_VERSIONS()->responseSchema(version));
	s->setIfExists(CommonFields::THROTTLE_TIME_MS, new Integer(throttleTimeMs_));
	s->set(CommonFields::ERROR_CODE, error_->code());
	std::list<Struct*> apiVersionList;
	for (std::map<short, ApiVersion>::iterator iter = apiKeyToApiVersion.begin(); iter != apiKeyToApiVersion.end(); iter++)
	{
		ApiVersion &apiVersion = iter->second;
		Struct *apiVersionStruct = s->instance(API_VERSIONS_KEY_NAME);
		apiVersionStruct->set(API_KEY_NAME, new Short(apiVersion.apiKey));
		apiVersionStruct->set(MIN_VERSION_KEY_NAME, new Short(apiVersion.minVersion));
		apiVersionStruct->set(MAX_VERSION_KEY_NAME, new Short(apiVersion.maxVersion));
		apiVersionList.push_back(apiVersionStruct);
	}
	s->set(API_VERSIONS_KEY_NAME, Arrays::toArray(apiVersionList));
	return s;
}

void ApiVersionsResponse::init(int throttleTimeMs, Errors *error, std::list<ApiVersion> apiVersions)
{
	this->throttleTimeMs_ = throttleTimeMs;
	this->error_ = error;
	this->apiKeyToApiVersion = buildApiKeyToApiVersion(apiVersions);
}

std::map<short, ApiVersion> ApiVersionsResponse::buildApiKeyToApiVersion(std::list<ApiVersion> apiVersions)
{
	std::map<short, ApiVersion> tempApiIdToApiVersion;
	for (auto iter : apiVersions)
	{
		tempApiIdToApiVersion[iter.apiKey] = iter;
	}
	return tempApiIdToApiVersion;
}

ApiVersion::ApiVersion()
{

}

ApiVersion::ApiVersion(ApiKeys *apiKey)
{
	init(apiKey->id, apiKey->oldestVersion(), apiKey->latestVersion());
}

ApiVersion::ApiVersion(short apiKey, short minVersion, short maxVersion)
{
	init(apiKey, minVersion, maxVersion);
}

std::string ApiVersion::toString()
{
	return "ApiVersion("
		"apiKey=" + std::to_string(apiKey) +
		", minVersion=" + std::to_string(minVersion) +
		", maxVersion= " + std::to_string(maxVersion) +
		")";
}

void ApiVersion::init(short apiKey, short minVersion, short maxVersion)
{
	this->apiKey = apiKey;
	this->minVersion = minVersion;
	this->maxVersion = maxVersion;
}