#ifndef __KFK_RESPONSEHEADER_H__
#define __KFK_RESPONSEHEADER_H__

#pragma once
#include "AbstractRequestResponse.h"
class Schema;
class BoundField;

class ResponseHeader
	: public AbstractRequestResponse
{
public:
	static Schema *SCHEMA;

	ResponseHeader(Struct *s);
	ResponseHeader(int correlationId);

	int sizeOf();

	Struct* toStruct();

	int correlationId();

	static ResponseHeader* parse(ByteBuffer *buffer);

private:
	static BoundField *CORRELATION_KEY_FIELD;
	int correlationId_;
};

#endif // !__KFK_RESPONSEHEADER_H__
