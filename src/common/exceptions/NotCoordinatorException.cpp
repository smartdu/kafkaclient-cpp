#include "NotCoordinatorException.h"

NotCoordinatorException::NotCoordinatorException(std::string message)
    : ApiException(message.c_str())
{

}
