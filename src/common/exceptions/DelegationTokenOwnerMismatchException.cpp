#include "DelegationTokenOwnerMismatchException.h"

DelegationTokenOwnerMismatchException::DelegationTokenOwnerMismatchException(std::string message)
    : ApiException(message.c_str())
{

}
