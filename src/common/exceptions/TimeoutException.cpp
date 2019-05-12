#include "TimeoutException.h"

TimeoutException::TimeoutException(std::string message)
    : ApiException(message.c_str())
{

}
