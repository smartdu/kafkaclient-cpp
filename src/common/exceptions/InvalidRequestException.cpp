#include "InvalidRequestException.h"

InvalidRequestException::InvalidRequestException(std::string message)
    : ApiException(message.c_str())
{

}
