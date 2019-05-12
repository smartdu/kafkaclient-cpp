#ifndef __KFK_SASLAUTHENTICATIONEXCEPTION_H__
#define __KFK_SASLAUTHENTICATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class SaslAuthenticationException
    : public ApiException
{
public:
    SaslAuthenticationException() : ApiException("") {}
    SaslAuthenticationException(std::string message);
    virtual ~SaslAuthenticationException()
    {

    }
    static SaslAuthenticationException* new0()
    {
        return new SaslAuthenticationException();
    }
};

#endif // !__KFK_SASLAUTHENTICATIONEXCEPTION_H__
