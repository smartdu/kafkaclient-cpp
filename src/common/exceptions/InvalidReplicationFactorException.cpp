#include "InvalidReplicationFactorException.h"

InvalidReplicationFactorException::InvalidReplicationFactorException(std::string message)
    : ApiException(message.c_str())
{

}
