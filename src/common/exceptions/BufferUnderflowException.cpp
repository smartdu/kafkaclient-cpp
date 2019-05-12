#include "BufferUnderflowException.h"

BufferUnderflowException::BufferUnderflowException(std::string message)
    : ApiException(message.c_str())
{

}
