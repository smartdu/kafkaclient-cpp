#include "InvalidSessionTimeoutException.h"

InvalidSessionTimeoutException::InvalidSessionTimeoutException(std::string message)
    : ApiException(message.c_str())
{

}
