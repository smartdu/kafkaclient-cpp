#include "InvalidPrincipalTypeException.h"

InvalidPrincipalTypeException::InvalidPrincipalTypeException(std::string message)
    : ApiException(message.c_str())
{

}
