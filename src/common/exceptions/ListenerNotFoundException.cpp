#include "ListenerNotFoundException.h"

ListenerNotFoundException::ListenerNotFoundException(std::string message)
    : ApiException(message.c_str())
{

}
