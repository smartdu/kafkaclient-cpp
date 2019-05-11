#include "UnknownServerException.h"

UnknownServerException::UnknownServerException(std::string message)
    : ApiException(message.c_str())
{

}
