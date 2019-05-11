#ifndef __KFK_INVALIDSESSIONTIMEOUTEXCEPTION_H__
#define __KFK_INVALIDSESSIONTIMEOUTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidSessionTimeoutException
    : public ApiException
{
public:
    InvalidSessionTimeoutException() : ApiException("") {}
    InvalidSessionTimeoutException(std::string message);
    virtual ~InvalidSessionTimeoutException()
    {

    }
    static InvalidSessionTimeoutException* new0()
    {
        return new InvalidSessionTimeoutException();
    }
};

#endif // !__KFK_INVALIDSESSIONTIMEOUTEXCEPTION_H__
