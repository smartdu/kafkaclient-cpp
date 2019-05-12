#include "NotControllerException.h"

NotControllerException::NotControllerException(std::string message)
    : ApiException(message.c_str())
{

}
