#include "GroupIdNotFoundException.h"

GroupIdNotFoundException::GroupIdNotFoundException(std::string message)
    : ApiException(message.c_str())
{

}
