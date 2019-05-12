#include "GroupNotEmptyException.h"

GroupNotEmptyException::GroupNotEmptyException(std::string message)
    : ApiException(message.c_str())
{

}
