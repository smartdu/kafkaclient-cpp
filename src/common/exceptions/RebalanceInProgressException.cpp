#include "RebalanceInProgressException.h"

RebalanceInProgressException::RebalanceInProgressException(std::string message)
    : ApiException(message.c_str())
{

}
