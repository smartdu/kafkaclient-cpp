#include "LeaderNotAvailableException.h"

LeaderNotAvailableException::LeaderNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
