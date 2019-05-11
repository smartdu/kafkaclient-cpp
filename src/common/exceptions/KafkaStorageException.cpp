#include "KafkaStorageException.h"

KafkaStorageException::KafkaStorageException(std::string message)
    : ApiException(message.c_str())
{

}
