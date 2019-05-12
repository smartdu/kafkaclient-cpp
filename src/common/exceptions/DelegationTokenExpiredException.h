#ifndef __KFK_DELEGATIONTOKENEXPIREDEXCEPTION_H__
#define __KFK_DELEGATIONTOKENEXPIREDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DelegationTokenExpiredException
    : public ApiException
{
public:
    DelegationTokenExpiredException() : ApiException("") {}
    DelegationTokenExpiredException(std::string message);
    virtual ~DelegationTokenExpiredException()
    {

    }
    static DelegationTokenExpiredException* new0()
    {
        return new DelegationTokenExpiredException();
    }
};

#endif // !__KFK_DELEGATIONTOKENEXPIREDEXCEPTION_H__
