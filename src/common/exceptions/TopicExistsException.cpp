#include "TopicExistsException.h"

TopicExistsException::TopicExistsException(std::string message)
    : ApiException(message.c_str())
{

}
