#include "ReplicaNotAvailableException.h"

ReplicaNotAvailableException::ReplicaNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
