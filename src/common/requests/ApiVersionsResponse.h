#ifndef __KFK_APIVERSIONRESPONSE_H__
#define __KFK_APIVERSIONRESPONSE_H__

#pragma once
#include "AbstractResponse.h"
#include "Object.h"
#include <list>
class Schema;
class ApiKeys;
class Errors;
class Struct;

class ApiVersion
	: public Object
{
public:
	short apiKey;
	short minVersion;
	short maxVersion;

public:
	ApiVersion();
	ApiVersion(ApiKeys *apiKey);
	ApiVersion(short apiKey, short minVersion, short maxVersion);
	virtual ~ApiVersion()
	{

	}

	virtual std::string toString();

protected:
	void init(short apiKey, short minVersion, short maxVersion);
};

class ApiVersionsResponse
	: public AbstractResponse
{
public:
	static Schema** schemaVersions();

	ApiVersionsResponse(Errors *error, std::list<ApiVersion> apiVersions);
	ApiVersionsResponse(int throttleTimeMs, Errors *error, std::list<ApiVersion> apiVersions);
	ApiVersionsResponse(Struct *s);

	static ApiVersionsResponse* apiVersionsResponse(int throttleTimeMs, char maxMagic);

	virtual int throttleTimeMs();

	std::list<ApiVersion> apiVersions();

	ApiVersion apiVersion(short apiKey);

	Errors* error();

	std::map<Errors*, int> errorCounts();

	static ApiVersionsResponse* parse(ByteBuffer *buffer, short version);

	static ApiVersionsResponse* createApiVersionsResponse(int throttleTimeMs, char minMagic);

	static ApiVersionsResponse* defaultApiVersionsResponse();

	virtual bool shouldClientThrottle(short version);

    static void destroy();

protected:
	virtual Struct* toStruct(short version);

	void init(int throttleTimeMs, Errors *error, std::list<ApiVersion> apiVersions);

private:
	std::map<short, ApiVersion> buildApiKeyToApiVersion(std::list<ApiVersion> apiVersions);

private:
	static const char* API_VERSIONS_KEY_NAME;
	static const char* API_KEY_NAME;
	static const char* MIN_VERSION_KEY_NAME;
	static const char* MAX_VERSION_KEY_NAME;

	static Schema* API_VERSIONS_V0;
	static Schema* API_VERSIONS_RESPONSE_V0;
	static Schema* API_VERSIONS_RESPONSE_V1;
	static Schema* API_VERSIONS_RESPONSE_V2;

	static ApiVersionsResponse *defaultApiVersionsResponse_;

	Errors *error_;
	int throttleTimeMs_;
	std::map<short, ApiVersion> apiKeyToApiVersion;
};

#endif // !__KFK_APIVERSIONRESPONSE_H__
