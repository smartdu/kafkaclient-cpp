#include "InconsistentGroupProtocolException.h"

InconsistentGroupProtocolException::InconsistentGroupProtocolException(std::string message)
    : ApiException(message.c_str())
{

}
