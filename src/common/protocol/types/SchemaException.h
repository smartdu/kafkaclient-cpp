#ifndef __KFK_SCHEMAEXCEPTION_H__
#define __KFK_SCHEMAEXCEPTION_H__

#pragma once
#include <string>
#include "KafkaException.h"

class SchemaException
	: public KafkaException
{
public:
	SchemaException(std::string message);
	virtual ~SchemaException()
	{

	}
};

#endif // !__KFK_SCHEMAEXCEPTION_H__
