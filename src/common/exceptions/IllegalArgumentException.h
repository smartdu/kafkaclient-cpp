#ifndef __KFK_ILLEGALARGUMENTEXCEPTION_H__
#define __KFK_ILLEGALARGUMENTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class IllegalArgumentException
    : public ApiException
{
public:
    IllegalArgumentException() : ApiException("") {}
    IllegalArgumentException(std::string message);
    virtual ~IllegalArgumentException()
    {

    }
    static IllegalArgumentException* new0()
    {
        return new IllegalArgumentException();
    }
};

#endif // !__KFK_ILLEGALARGUMENTEXCEPTION_H__
