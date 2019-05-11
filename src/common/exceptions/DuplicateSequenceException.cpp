#include "DuplicateSequenceException.h"

DuplicateSequenceException::DuplicateSequenceException(std::string message)
    : ApiException(message.c_str())
{

}
