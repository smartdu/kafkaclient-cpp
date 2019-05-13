#include "ApiVersionsRequest.h"
#include "Short.h"
#include "ByteBuffer.h"
#include "Struct.h"
#include "ApiKeys.h"

Schema *ApiVersionsRequest::API_VERSIONS_REQUEST_V0 = new Schema(0);
Schema *ApiVersionsRequest::API_VERSIONS_REQUEST_V1 = API_VERSIONS_REQUEST_V0->clone();
Schema *ApiVersionsRequest::API_VERSIONS_REQUEST_V2 = API_VERSIONS_REQUEST_V1->clone();

Schema** ApiVersionsRequest::schemaVersions()
{
	static Schema* schemas[] = { API_VERSIONS_REQUEST_V0, API_VERSIONS_REQUEST_V1, API_VERSIONS_REQUEST_V2, NULL };
	return schemas;
}

ApiVersionsRequest::ApiVersionsRequest(short version)
{
	new (this)ApiVersionsRequest(version, NULL);
}

ApiVersionsRequest::ApiVersionsRequest(short version, Short *unsupportedRequestVersion)
	: AbstractRequest()
{
	this->unsupportedRequestVersion = unsupportedRequestVersion;
}

ApiVersionsRequest::ApiVersionsRequest(Struct *s, short version)
{
	new (this)ApiVersionsRequest(version, NULL);
}

bool ApiVersionsRequest::hasUnsupportedRequestVersion()
{
	return unsupportedRequestVersion != NULL;
}

ApiVersionsRequest* ApiVersionsRequest::parse(ByteBuffer *buffer, short version)
{
	return new ApiVersionsRequest(ApiKeys::API_VERSIONS()->parseRequest(version, buffer), version);
}

Struct* ApiVersionsRequest::toStruct()
{
	return new Struct(ApiKeys::API_VERSIONS()->requestSchema(version()));
}