#include "InvalidMetadataException.h"

InvalidMetadataException::InvalidMetadataException(std::string message)
	: KafkaException(message.c_str())
{

}