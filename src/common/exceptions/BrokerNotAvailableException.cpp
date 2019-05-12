#include "BrokerNotAvailableException.h"

BrokerNotAvailableException::BrokerNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
