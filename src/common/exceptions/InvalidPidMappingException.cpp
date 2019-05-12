#include "InvalidPidMappingException.h"

InvalidPidMappingException::InvalidPidMappingException(std::string message)
    : ApiException(message.c_str())
{

}
