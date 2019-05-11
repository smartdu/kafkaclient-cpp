#include "ControllerMovedException.h"

ControllerMovedException::ControllerMovedException(std::string message)
    : ApiException(message.c_str())
{

}
