#ifndef __KFK_BUFFERUNDERFLOWEXCEPTION_H__
#define __KFK_BUFFERUNDERFLOWEXCEPTION_H__

#pragma once
#include "KafkaException.h"

class BufferUnderflowException
	: public KafkaException
{
public:
	BufferUnderflowException(std::string message);
	virtual ~BufferUnderflowException()
	{

	}
};

#endif // !__KFK_BUFFERUNDERFLOWEXCEPTION_H__
