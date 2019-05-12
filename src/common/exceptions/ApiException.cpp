#include "ApiException.h"

ApiException::ApiException(std::string message)
    : KafkaException(message.c_str())
{

}
