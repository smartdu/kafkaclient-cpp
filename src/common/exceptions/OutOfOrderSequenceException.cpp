#include "OutOfOrderSequenceException.h"

OutOfOrderSequenceException::OutOfOrderSequenceException(std::string message)
    : ApiException(message.c_str())
{

}
