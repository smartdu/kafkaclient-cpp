#include "InvalidTxnStateException.h"

InvalidTxnStateException::InvalidTxnStateException(std::string message)
    : ApiException(message.c_str())
{

}
