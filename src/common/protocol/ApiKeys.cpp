#include "ApiKeys.h"
#include "RecordBatch.h"
#include "IllegalArgumentException.h"
#include "ApiVersionsRequest.h"
#include "ApiVersionsResponse.h"
#include "Schema.h"
#include "ByteBuffer.h"
#include "SchemaException.h"
#include "MetadataRequest.h"
#include "MetadataResponse.h"
#include "OffsetFetchRequest.h"
#include "OffsetFetchResponse.h"

std::list<ApiKeys*> ApiKeys::values_ = std::list<ApiKeys*>();

ApiKeys* ApiKeys::API_VERSIONS()
{
	static ApiKeys *once = new ApiKeys_API_VERSIONS;
	return once;
}

ApiKeys* ApiKeys::METADATA()
{
	static ApiKeys *once = new ApiKeys(3, "Metadata", MetadataRequest::schemaVersions(), MetadataResponse::schemaVersions());
	return once;
}

ApiKeys* ApiKeys::OFFSET_FETCH()
{
    static ApiKeys *once = new ApiKeys(9, "OffsetFetch", OffsetFetchRequest::schemaVersions(), OffsetFetchResponse::schemaVersions());
    return once;
}

ApiKeys::ApiKeys(int id, const char* name, Schema** requestSchemas, Schema** responseSchemas)
{
	init(id, name, false, RecordBatch::MAGIC_VALUE_V0, requestSchemas, responseSchemas);
}

ApiKeys::ApiKeys(int id, const char* name, bool clusterAction, Schema** requestSchemas, Schema** responseSchemas)
{
	init(id, name, clusterAction, RecordBatch::MAGIC_VALUE_V0, requestSchemas, responseSchemas);
}

ApiKeys::ApiKeys(int id, const char* name, bool clusterAction, char minRequiredInterBrokerMagic,
	Schema** requestSchemas, Schema** responseSchemas)
{
	init(id, name, clusterAction, minRequiredInterBrokerMagic, requestSchemas, responseSchemas);
}

ApiKeys::~ApiKeys()
{
    // Schema¼Ì³ÐType£¬ÓÉTypeÎö¹¹
    /*for (int i = 0; requestSchemas[i] != NULL; ++i)
    {
        Schema::destroy(requestSchemas[i]);
    }

    for (int i = 0; responseSchemas[i] != NULL; ++i)
    {
        Schema::destroy(responseSchemas[i]);
    }*/
}

void ApiKeys::init(int id, const char* name, bool clusterAction, char minRequiredInterBrokerMagic,
	Schema** requestSchemas, Schema** responseSchemas)
{
	if (id < 0)
		throw IllegalArgumentException("id must not be negative, id: " + id);
	this->id = (short)id;
	this->name = name;
	this->clusterAction = clusterAction;
	this->minRequiredInterBrokerMagic = minRequiredInterBrokerMagic;

	/*if (requestSchemas.length != responseSchemas.length)
		throw IllegalStateException(requestSchemas.length + " request versions for api " + name
			+ " but " + responseSchemas.length + " response versions.");

	for (int i = 0; requestSchemas[i] != NULL; ++i) {
		if (requestSchemas[i] == NULL)
			throw IllegalStateException("Request schema for api " + name + " for version " + i + " is null");
		if (responseSchemas[i] == NULL)
			throw IllegalStateException("Response schema for api " + name + " for version " + i + " is null");
	}*/

	bool requestRetainsBufferReference = false;
	for (int i = 0; requestSchemas[i] != NULL; ++i)
	{
		if (retainsBufferReference(requestSchemas[i]))
		{
			requestRetainsBufferReference = true;
			break;
		}
	}
	this->requiresDelayedAllocation = requestRetainsBufferReference;
	this->requestSchemas = requestSchemas;
	this->responseSchemas = responseSchemas;

    values_.push_back(this);
}

Struct* ApiKeys::parseRequest(short version, ByteBuffer *buffer)
{
	return (Struct*)requestSchema(version)->read(buffer);
}

Struct* ApiKeys::parseResponse(short version, ByteBuffer *buffer)
{
	return (Struct*)responseSchema(version)->read(buffer);
}

Schema* ApiKeys::requestSchema(short version)
{
	return schemaFor(requestSchemas, version);
}

Schema* ApiKeys::responseSchema(short version)
{
	return schemaFor(responseSchemas, version);
}

short ApiKeys::latestVersion()
{
	short i = 0;
	for (i = 0; requestSchemas[i] != NULL; i++);
	return i;
}

short ApiKeys::oldestVersion()
{
	return 0;
}

bool ApiKeys::isVersionSupported(short apiVersion)
{
	return apiVersion >= oldestVersion() && apiVersion <= latestVersion();
}

std::list<ApiKeys*> ApiKeys::values()
{
    return values_;
}

Struct* ApiKeys::parseResponse(short version, ByteBuffer *buffer, short fallbackVersion)
{
	int bufferPosition = buffer->position();
	try
	{
		return (Struct*)responseSchema(version)->read(buffer);
	}
	catch (SchemaException e)
	{
		if (version != fallbackVersion)
		{
			buffer->position(bufferPosition);
			return (Struct*)responseSchema(fallbackVersion)->read(buffer);
		}
		else
			throw e;
	}
}

bool ApiKeys::retainsBufferReference(Schema *schema)
{
	return false;
}

Schema* ApiKeys::schemaFor(Schema **versions, short version)
{
	if (!isVersionSupported(version))
		throw IllegalArgumentException("Invalid version for API key " + this->toString() + ": " + std::to_string(version));
	return versions[version];
}

ApiKeys_API_VERSIONS::ApiKeys_API_VERSIONS()
	: ApiKeys(18, "ApiVersions", ApiVersionsRequest::schemaVersions(), ApiVersionsResponse::schemaVersions())
{

}

Struct* ApiKeys_API_VERSIONS::parseResponse(short version, ByteBuffer *buffer)
{
	return ApiKeys::parseResponse(version, buffer, (short)0);
}
