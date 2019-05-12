#include "UnsupportedByAuthenticationException.h"

UnsupportedByAuthenticationException::UnsupportedByAuthenticationException(std::string message)
    : ApiException(message.c_str())
{

}
