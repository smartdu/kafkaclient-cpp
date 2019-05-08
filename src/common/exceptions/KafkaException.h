#ifndef __KFK_KAFKAEXCEPTION_H__
#define __KFK_KAFKAEXCEPTION_H__

#pragma once
#include "Object.h"
#include <string>

class KafkaException
	: public Object
{
public:
	KafkaException(const char *message);

	virtual std::string toString();

private:
	std::string message_;
};

#endif // !__KFK_KAFKAEXCEPTION_H__
