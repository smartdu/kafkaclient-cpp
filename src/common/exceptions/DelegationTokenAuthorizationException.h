#ifndef __KFK_DELEGATIONTOKENAUTHORIZATIONEXCEPTION_H__
#define __KFK_DELEGATIONTOKENAUTHORIZATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DelegationTokenAuthorizationException
    : public ApiException
{
public:
    DelegationTokenAuthorizationException() : ApiException("") {}
    DelegationTokenAuthorizationException(std::string message);
    virtual ~DelegationTokenAuthorizationException()
    {

    }
    static DelegationTokenAuthorizationException* new0()
    {
        return new DelegationTokenAuthorizationException();
    }
};

#endif // !__KFK_DELEGATIONTOKENAUTHORIZATIONEXCEPTION_H__
