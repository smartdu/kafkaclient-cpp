#include "InvalidTxnTimeoutException.h"

InvalidTxnTimeoutException::InvalidTxnTimeoutException(std::string message)
    : ApiException(message.c_str())
{

}
