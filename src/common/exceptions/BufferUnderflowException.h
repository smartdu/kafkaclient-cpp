#ifndef __KFK_BUFFERUNDERFLOWEXCEPTION_H__
#define __KFK_BUFFERUNDERFLOWEXCEPTION_H__

#pragma once
#include "ApiException.h"

class BufferUnderflowException
    : public ApiException
{
public:
    BufferUnderflowException() : ApiException("") {}
    BufferUnderflowException(std::string message);
    virtual ~BufferUnderflowException()
    {

    }
    static BufferUnderflowException* new0()
    {
        return new BufferUnderflowException();
    }
};

#endif // !__KFK_BUFFERUNDERFLOWEXCEPTION_H__
