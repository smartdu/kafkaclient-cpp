#include "NotEnoughReplicasException.h"

NotEnoughReplicasException::NotEnoughReplicasException(std::string message)
    : ApiException(message.c_str())
{

}
