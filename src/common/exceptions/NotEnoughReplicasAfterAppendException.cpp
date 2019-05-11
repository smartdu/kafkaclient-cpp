#include "NotEnoughReplicasAfterAppendException.h"

NotEnoughReplicasAfterAppendException::NotEnoughReplicasAfterAppendException(std::string message)
    : ApiException(message.c_str())
{

}
