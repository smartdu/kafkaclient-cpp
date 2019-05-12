#include "InvalidMetadataException.h"

InvalidMetadataException::InvalidMetadataException(std::string message)
    : ApiException(message.c_str())
{

}
