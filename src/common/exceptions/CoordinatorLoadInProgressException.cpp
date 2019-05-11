#include "CoordinatorLoadInProgressException.h"

CoordinatorLoadInProgressException::CoordinatorLoadInProgressException(std::string message)
    : ApiException(message.c_str())
{

}
