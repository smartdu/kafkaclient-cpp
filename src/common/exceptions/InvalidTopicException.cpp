#include "InvalidTopicException.h"

InvalidTopicException::InvalidTopicException(std::string message)
    : ApiException(message.c_str())
{

}
