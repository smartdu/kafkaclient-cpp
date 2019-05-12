#include "DelegationTokenAuthorizationException.h"

DelegationTokenAuthorizationException::DelegationTokenAuthorizationException(std::string message)
    : ApiException(message.c_str())
{

}
