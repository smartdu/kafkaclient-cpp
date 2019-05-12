#include "ReassignmentInProgressException.h"

ReassignmentInProgressException::ReassignmentInProgressException(std::string message)
    : ApiException(message.c_str())
{

}
