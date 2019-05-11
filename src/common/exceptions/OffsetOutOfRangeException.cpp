#include "OffsetOutOfRangeException.h"

OffsetOutOfRangeException::OffsetOutOfRangeException(std::string message)
    : ApiException(message.c_str())
{

}
