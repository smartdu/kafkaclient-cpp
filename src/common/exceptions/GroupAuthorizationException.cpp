#include "GroupAuthorizationException.h"

GroupAuthorizationException::GroupAuthorizationException(std::string message)
    : ApiException(message.c_str())
{

}
