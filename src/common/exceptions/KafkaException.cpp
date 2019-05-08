#include "KafkaException.h"

KafkaException::KafkaException(const char *message)
	: message_(message)
{

}

std::string KafkaException::toString()
{
	return message_;
}