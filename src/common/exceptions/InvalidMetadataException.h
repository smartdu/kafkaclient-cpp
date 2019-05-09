#ifndef __KFK_INVALIDMETADATAEXCEPTION_H__
#define __KFK_INVALIDMETADATAEXCEPTION_H__

#pragma once
#include <string>
#include "KafkaException.h"

class InvalidMetadataException
	: public KafkaException
{
public:
	InvalidMetadataException(std::string message);
	virtual ~InvalidMetadataException()
	{

	}
};

#endif // !__KFK_INVALIDMETADATAEXCEPTION_H__
