#include "UnknownTopicOrPartitionException.h"

UnknownTopicOrPartitionException::UnknownTopicOrPartitionException(std::string message)
    : ApiException(message.c_str())
{

}
