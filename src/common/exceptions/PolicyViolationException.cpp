#include "PolicyViolationException.h"

PolicyViolationException::PolicyViolationException(std::string message)
    : ApiException(message.c_str())
{

}
