#include "SaslAuthenticationException.h"

SaslAuthenticationException::SaslAuthenticationException(std::string message)
    : ApiException(message.c_str())
{

}
