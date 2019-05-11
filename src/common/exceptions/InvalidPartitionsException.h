#ifndef __KFK_INVALIDPARTITIONSEXCEPTION_H__
#define __KFK_INVALIDPARTITIONSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidPartitionsException
    : public ApiException
{
public:
    InvalidPartitionsException() : ApiException("") {}
    InvalidPartitionsException(std::string message);
    virtual ~InvalidPartitionsException()
    {

    }
    static InvalidPartitionsException* new0()
    {
        return new InvalidPartitionsException();
    }
};

#endif // !__KFK_INVALIDPARTITIONSEXCEPTION_H__
