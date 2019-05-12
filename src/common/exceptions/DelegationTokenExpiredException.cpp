#include "DelegationTokenExpiredException.h"

DelegationTokenExpiredException::DelegationTokenExpiredException(std::string message)
    : ApiException(message.c_str())
{

}
