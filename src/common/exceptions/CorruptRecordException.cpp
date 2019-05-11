#include "CorruptRecordException.h"

CorruptRecordException::CorruptRecordException(std::string message)
    : ApiException(message.c_str())
{

}
