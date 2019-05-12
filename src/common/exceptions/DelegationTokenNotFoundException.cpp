#include "DelegationTokenNotFoundException.h"

DelegationTokenNotFoundException::DelegationTokenNotFoundException(std::string message)
    : ApiException(message.c_str())
{

}
