#include "RecordBatchTooLargeException.h"

RecordBatchTooLargeException::RecordBatchTooLargeException(std::string message)
    : ApiException(message.c_str())
{

}
