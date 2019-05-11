#include "LogDirNotFoundException.h"

LogDirNotFoundException::LogDirNotFoundException(std::string message)
    : ApiException(message.c_str())
{

}
