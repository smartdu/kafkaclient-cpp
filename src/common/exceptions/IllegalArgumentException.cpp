#include "IllegalArgumentException.h"

IllegalArgumentException::IllegalArgumentException(std::string message)
	: KafkaException(message.c_str())
{

}