#include "NotLeaderForPartitionException.h"

NotLeaderForPartitionException::NotLeaderForPartitionException(std::string message)
    : ApiException(message.c_str())
{

}
