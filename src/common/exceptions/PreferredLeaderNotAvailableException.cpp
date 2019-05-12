#include "PreferredLeaderNotAvailableException.h"

PreferredLeaderNotAvailableException::PreferredLeaderNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
