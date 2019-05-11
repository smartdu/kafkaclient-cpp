#include "OffsetNotAvailableException.h"

OffsetNotAvailableException::OffsetNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
