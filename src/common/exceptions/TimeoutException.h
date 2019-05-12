#ifndef __KFK_TIMEOUTEXCEPTION_H__
#define __KFK_TIMEOUTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TimeoutException
    : public ApiException
{
public:
    TimeoutException() : ApiException("") {}
    TimeoutException(std::string message);
    virtual ~TimeoutException()
    {

    }
    static TimeoutException* new0()
    {
        return new TimeoutException();
    }
};

#endif // !__KFK_TIMEOUTEXCEPTION_H__
