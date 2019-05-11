#include "UnknownProducerIdException.h"

UnknownProducerIdException::UnknownProducerIdException(std::string message)
    : ApiException(message.c_str())
{

}
