#include "NetworkException.h"

NetworkException::NetworkException(std::string message)
    : ApiException(message.c_str())
{

}
