#include "GroupMaxSizeReachedException.h"

GroupMaxSizeReachedException::GroupMaxSizeReachedException(std::string message)
    : ApiException(message.c_str())
{

}
