#include "InvalidRequiredAcksException.h"

InvalidRequiredAcksException::InvalidRequiredAcksException(std::string message)
    : ApiException(message.c_str())
{

}
