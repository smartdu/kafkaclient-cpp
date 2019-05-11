#include "InvalidTimestampException.h"

InvalidTimestampException::InvalidTimestampException(std::string message)
    : ApiException(message.c_str())
{

}
