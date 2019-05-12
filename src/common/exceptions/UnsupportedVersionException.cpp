#include "UnsupportedVersionException.h"

UnsupportedVersionException::UnsupportedVersionException(std::string message)
    : ApiException(message.c_str())
{

}
