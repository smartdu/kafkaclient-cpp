#include "IllegalGenerationException.h"

IllegalGenerationException::IllegalGenerationException(std::string message)
    : ApiException(message.c_str())
{

}
