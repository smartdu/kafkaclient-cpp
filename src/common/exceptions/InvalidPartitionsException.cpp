#include "InvalidPartitionsException.h"

InvalidPartitionsException::InvalidPartitionsException(std::string message)
    : ApiException(message.c_str())
{

}
