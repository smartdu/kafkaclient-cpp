#ifndef __KFK_ILLEGALARGUMENTEXCEPTION_H__
#define __KFK_ILLEGALARGUMENTEXCEPTION_H__

#pragma once
#include <string>
#include "KafkaException.h"

class IllegalArgumentException
	: public KafkaException
{
public:
	IllegalArgumentException(std::string message);
};

#endif // !__KFK_ILLEGALARGUMENTEXCEPTION_H__
