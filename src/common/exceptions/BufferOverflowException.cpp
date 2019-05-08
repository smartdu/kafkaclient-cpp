#include "BufferOverflowException.h"

BufferOverflowException::BufferOverflowException(std::string message)
	: KafkaException(message.c_str())
{

}