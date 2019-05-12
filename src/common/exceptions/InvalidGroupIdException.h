#ifndef __KFK_INVALIDGROUPIDEXCEPTION_H__
#define __KFK_INVALIDGROUPIDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidGroupIdException
    : public ApiException
{
public:
    InvalidGroupIdException() : ApiException("") {}
    InvalidGroupIdException(std::string message);
    virtual ~InvalidGroupIdException()
    {

    }
    static InvalidGroupIdException* new0()
    {
        return new InvalidGroupIdException();
    }
};

#endif // !__KFK_INVALIDGROUPIDEXCEPTION_H__
