#include "IllegalSaslStateException.h"

IllegalSaslStateException::IllegalSaslStateException(std::string message)
    : ApiException(message.c_str())
{

}
