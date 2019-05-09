#ifndef __KFK_BUFFEROVERFLOWEXCEPTION_H__
#define __KFK_BUFFEROVERFLOWEXCEPTION_H__

#pragma once
#include "KafkaException.h"

class BufferOverflowException
	: public KafkaException
{
public:
	BufferOverflowException(std::string message);
	virtual ~BufferOverflowException()
	{

	}
};

#endif // !__KFK_BUFFEROVERFLOWEXCEPTION_H__
