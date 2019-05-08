#include "SchemaException.h"

SchemaException::SchemaException(std::string message)
	: KafkaException(message.c_str())
{

}