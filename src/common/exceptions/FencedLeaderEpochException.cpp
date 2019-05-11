#include "FencedLeaderEpochException.h"

FencedLeaderEpochException::FencedLeaderEpochException(std::string message)
    : ApiException(message.c_str())
{

}
