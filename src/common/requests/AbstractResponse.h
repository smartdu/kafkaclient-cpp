#ifndef __KFK_ABSTRACTRESPONSE_H__
#define __KFK_ABSTRACTRESPONSE_H__

#pragma once
#include "AbstractRequestResponse.h"
#include <map>
class Struct;
class ResponseHeader;
class ApiKeys;
class Errors;

class AbstractResponse
	: public AbstractRequestResponse
{
public:
	static const int DEFAULT_THROTTLE_TIME = 0;
	virtual ~AbstractResponse()
	{

	}

	ByteBuffer* serialize(short version, ResponseHeader *responseHeader);

	virtual std::map<Errors*, int> errorCounts() = 0;

	static AbstractResponse* parseResponse(ApiKeys *apiKey, Struct *s, short version);

protected:
	std::map<Errors*, int> errorCounts(Errors *error);

	virtual Struct* toStruct(short version) = 0;
};

#endif // !__KFK_ABSTRACTRESPONSE_H__
