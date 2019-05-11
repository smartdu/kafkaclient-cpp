#include "InvalidConfigurationException.h"

InvalidConfigurationException::InvalidConfigurationException(std::string message)
    : ApiException(message.c_str())
{

}
