#ifndef __KFK_LOGDIRNOTFOUNDEXCEPTION_H__
#define __KFK_LOGDIRNOTFOUNDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class LogDirNotFoundException
    : public ApiException
{
public:
    LogDirNotFoundException() : ApiException("") {}
    LogDirNotFoundException(std::string message);
    virtual ~LogDirNotFoundException()
    {

    }
    static LogDirNotFoundException* new0()
    {
        return new LogDirNotFoundException();
    }
};

#endif // !__KFK_LOGDIRNOTFOUNDEXCEPTION_H__
