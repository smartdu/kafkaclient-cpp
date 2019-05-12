#ifndef __KFK_BUFFEROVERFLOWEXCEPTION_H__
#define __KFK_BUFFEROVERFLOWEXCEPTION_H__

#pragma once
#include "ApiException.h"

class BufferOverflowException
    : public ApiException
{
public:
    BufferOverflowException() : ApiException("") {}
    BufferOverflowException(std::string message);
    virtual ~BufferOverflowException()
    {

    }
    static BufferOverflowException* new0()
    {
        return new BufferOverflowException();
    }
};

#endif // !__KFK_BUFFEROVERFLOWEXCEPTION_H__
