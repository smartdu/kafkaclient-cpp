#include "CoordinatorNotAvailableException.h"

CoordinatorNotAvailableException::CoordinatorNotAvailableException(std::string message)
    : ApiException(message.c_str())
{

}
