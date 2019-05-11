#include "StaleBrokerEpochException.h"

StaleBrokerEpochException::StaleBrokerEpochException(std::string message)
    : ApiException(message.c_str())
{

}
