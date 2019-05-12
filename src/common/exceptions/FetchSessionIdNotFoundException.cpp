#include "FetchSessionIdNotFoundException.h"

FetchSessionIdNotFoundException::FetchSessionIdNotFoundException(std::string message)
    : ApiException(message.c_str())
{

}
