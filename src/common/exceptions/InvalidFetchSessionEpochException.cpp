#include "InvalidFetchSessionEpochException.h"

InvalidFetchSessionEpochException::InvalidFetchSessionEpochException(std::string message)
    : ApiException(message.c_str())
{

}
