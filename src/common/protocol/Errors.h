#ifndef __KFK_ERRORS_H__
#define __KFK_ERRORS_H__

#pragma once
#include <map>
#include "Object.h"
class KafkaException;

class Errors
	: public Object
{
public:
	static Errors* UNKNOWN_SERVER_ERROR;
	static Errors* NONE;
	static Errors* TOPIC_AUTHORIZATION_FAILED;
	static Errors* INVALID_TOPIC_EXCEPTION;

	Errors(int code, const char *defaultExceptionString, KafkaException *exception = NULL);
	virtual ~Errors()
	{

	}

	static Errors* forCode(short code);

	short code();

	KafkaException* exception()
	{
		return exception_;
	}

private:
	short code_;
	KafkaException *exception_;
};

#endif // !__KFK_ERRORS_H__
