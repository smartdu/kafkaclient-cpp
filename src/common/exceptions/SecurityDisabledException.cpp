#include "SecurityDisabledException.h"

SecurityDisabledException::SecurityDisabledException(std::string message)
    : ApiException(message.c_str())
{

}
