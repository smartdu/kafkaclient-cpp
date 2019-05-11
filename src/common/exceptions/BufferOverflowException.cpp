#include "BufferOverflowException.h"

BufferOverflowException::BufferOverflowException(std::string message)
    : ApiException(message.c_str())
{

}
