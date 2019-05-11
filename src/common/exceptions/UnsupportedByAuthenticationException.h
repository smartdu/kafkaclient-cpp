#ifndef __KFK_UNSUPPORTEDBYAUTHENTICATIONEXCEPTION_H__
#define __KFK_UNSUPPORTEDBYAUTHENTICATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnsupportedByAuthenticationException
    : public ApiException
{
public:
    UnsupportedByAuthenticationException() : ApiException("") {}
    UnsupportedByAuthenticationException(std::string message);
    virtual ~UnsupportedByAuthenticationException()
    {

    }
    static UnsupportedByAuthenticationException* new0()
    {
        return new UnsupportedByAuthenticationException();
    }
};

#endif // !__KFK_UNSUPPORTEDBYAUTHENTICATIONEXCEPTION_H__
