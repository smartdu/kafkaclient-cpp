#include "OffsetMetadataTooLarge.h"

OffsetMetadataTooLarge::OffsetMetadataTooLarge(std::string message)
    : ApiException(message.c_str())
{

}
