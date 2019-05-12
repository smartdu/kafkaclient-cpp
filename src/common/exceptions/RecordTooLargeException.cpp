#include "RecordTooLargeException.h"

RecordTooLargeException::RecordTooLargeException(std::string message)
    : ApiException(message.c_str())
{

}
