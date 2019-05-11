#include "InvalidFetchSizeException.h"

InvalidFetchSizeException::InvalidFetchSizeException(std::string message)
    : ApiException(message.c_str())
{

}
