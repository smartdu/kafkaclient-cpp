#include "UnsupportedForMessageFormatException.h"

UnsupportedForMessageFormatException::UnsupportedForMessageFormatException(std::string message)
    : ApiException(message.c_str())
{

}
