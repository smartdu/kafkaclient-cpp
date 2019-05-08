#include "BufferUnderflowException.h"

BufferUnderflowException::BufferUnderflowException(std::string message)
	: KafkaException(message.c_str())
{

}