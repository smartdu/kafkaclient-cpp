#include "UnknownMemberIdException.h"

UnknownMemberIdException::UnknownMemberIdException(std::string message)
    : ApiException(message.c_str())
{

}
