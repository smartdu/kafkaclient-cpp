#include "OperationNotAttemptedException.h"

OperationNotAttemptedException::OperationNotAttemptedException(std::string message)
    : ApiException(message.c_str())
{

}
