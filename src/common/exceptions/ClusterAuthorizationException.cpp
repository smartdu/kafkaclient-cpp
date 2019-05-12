#include "ClusterAuthorizationException.h"

ClusterAuthorizationException::ClusterAuthorizationException(std::string message)
    : ApiException(message.c_str())
{

}
