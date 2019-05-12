#include "MemberIdRequiredException.h"

MemberIdRequiredException::MemberIdRequiredException(std::string message)
    : ApiException(message.c_str())
{

}
