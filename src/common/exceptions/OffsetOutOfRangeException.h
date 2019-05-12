#ifndef __KFK_OFFSETOUTOFRANGEEXCEPTION_H__
#define __KFK_OFFSETOUTOFRANGEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class OffsetOutOfRangeException
    : public ApiException
{
public:
    OffsetOutOfRangeException() : ApiException("") {}
    OffsetOutOfRangeException(std::string message);
    virtual ~OffsetOutOfRangeException()
    {

    }
    static OffsetOutOfRangeException* new0()
    {
        return new OffsetOutOfRangeException();
    }
};

#endif // !__KFK_OFFSETOUTOFRANGEEXCEPTION_H__
