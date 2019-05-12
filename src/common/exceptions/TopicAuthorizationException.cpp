#include "TopicAuthorizationException.h"

TopicAuthorizationException::TopicAuthorizationException(std::string message)
    : ApiException(message.c_str())
{

}
