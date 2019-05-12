#include "InvalidReplicaAssignmentException.h"

InvalidReplicaAssignmentException::InvalidReplicaAssignmentException(std::string message)
    : ApiException(message.c_str())
{

}
