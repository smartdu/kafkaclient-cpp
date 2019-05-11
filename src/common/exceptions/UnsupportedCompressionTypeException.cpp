#include "UnsupportedCompressionTypeException.h"

UnsupportedCompressionTypeException::UnsupportedCompressionTypeException(std::string message)
    : ApiException(message.c_str())
{

}
