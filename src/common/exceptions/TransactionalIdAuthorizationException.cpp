#include "TransactionalIdAuthorizationException.h"

TransactionalIdAuthorizationException::TransactionalIdAuthorizationException(std::string message)
    : ApiException(message.c_str())
{

}
