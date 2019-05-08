#ifndef __KFK_APIVERSIONREQUEST_H__
#define __KFK_APIVERSIONREQUEST_H__

#pragma once
#include "AbstractRequest.h"
#include "Schema.h"

class ApiVersionsRequest
	: public AbstractRequest
{
public:
	static Schema** schemaVersions();

	ApiVersionsRequest(short version);
	ApiVersionsRequest(short version, Short *unsupportedRequestVersion);
	ApiVersionsRequest(Struct *s, short version);

	bool hasUnsupportedRequestVersion();

	static ApiVersionsRequest* parse(ByteBuffer *buffer, short version);

protected:
	virtual Struct* toStruct();

private:
	static Schema *API_VERSIONS_REQUEST_V0;
	static Schema *API_VERSIONS_REQUEST_V1;
	static Schema *API_VERSIONS_REQUEST_V2;

	Short *unsupportedRequestVersion;
};

#endif // !__KFK_APIVERSIONREQUEST_H__
