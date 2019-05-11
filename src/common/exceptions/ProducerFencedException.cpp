#include "ProducerFencedException.h"

ProducerFencedException::ProducerFencedException(std::string message)
    : ApiException(message.c_str())
{

}
