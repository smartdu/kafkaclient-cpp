#include "UnknownLeaderEpochException.h"

UnknownLeaderEpochException::UnknownLeaderEpochException(std::string message)
    : ApiException(message.c_str())
{

}
