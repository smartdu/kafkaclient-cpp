#include "InvalidCommitOffsetSizeException.h"

InvalidCommitOffsetSizeException::InvalidCommitOffsetSizeException(std::string message)
    : ApiException(message.c_str())
{

}
