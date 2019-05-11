#include "IllegalArgumentException.h"

IllegalArgumentException::IllegalArgumentException(std::string message)
    : ApiException(message.c_str())
{

}
