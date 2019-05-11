#include "DelegationTokenDisabledException.h"

DelegationTokenDisabledException::DelegationTokenDisabledException(std::string message)
    : ApiException(message.c_str())
{

}
