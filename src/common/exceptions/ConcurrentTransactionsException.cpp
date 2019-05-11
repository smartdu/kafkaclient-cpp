#include "ConcurrentTransactionsException.h"

ConcurrentTransactionsException::ConcurrentTransactionsException(std::string message)
    : ApiException(message.c_str())
{

}
