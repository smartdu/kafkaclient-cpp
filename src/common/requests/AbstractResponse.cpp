#include "AbstractResponse.h"
#include "ResponseHeader.h"
#include "Struct.h"

ByteBuffer* AbstractResponse::serialize(short version, ResponseHeader *responseHeader)
{
	return AbstractRequestResponse::serialize(responseHeader->toStruct(), toStruct(version));
}

AbstractResponse* AbstractResponse::parseResponse(ApiKeys *apiKey, Struct *s, short version)
{
	return NULL;
}

std::map<Errors*, int> AbstractResponse::errorCounts(Errors *error)
{
	std::map<Errors*, int> s;
	s[error] = 1;
	return s;
}

void AbstractResponse::updateErrorCounts(std::map<Errors*, int> errorCounts, Errors *error)
{
	int count = errorCounts[error];
	errorCounts[error] = count + 1;
}