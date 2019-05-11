#ifndef __KFK_INVALIDTIMESTAMPEXCEPTION_H__
#define __KFK_INVALIDTIMESTAMPEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidTimestampException
    : public ApiException
{
public:
    InvalidTimestampException() : ApiException("") {}
    InvalidTimestampException(std::string message);
    virtual ~InvalidTimestampException()
    {

    }
    static InvalidTimestampException* new0()
    {
        return new InvalidTimestampException();
    }
};

#endif // !__KFK_INVALIDTIMESTAMPEXCEPTION_H__
