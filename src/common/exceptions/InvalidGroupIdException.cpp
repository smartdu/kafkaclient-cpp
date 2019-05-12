#include "InvalidGroupIdException.h"

InvalidGroupIdException::InvalidGroupIdException(std::string message)
    : ApiException(message.c_str())
{

}
