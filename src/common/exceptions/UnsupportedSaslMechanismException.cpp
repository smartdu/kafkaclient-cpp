#include "UnsupportedSaslMechanismException.h"

UnsupportedSaslMechanismException::UnsupportedSaslMechanismException(std::string message)
    : ApiException(message.c_str())
{

}
