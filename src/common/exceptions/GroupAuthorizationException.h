#ifndef __KFK_GROUPAUTHORIZATIONEXCEPTION_H__
#define __KFK_GROUPAUTHORIZATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class GroupAuthorizationException
    : public ApiException
{
public:
    GroupAuthorizationException() : ApiException("") {}
    GroupAuthorizationException(std::string message);
    virtual ~GroupAuthorizationException()
    {

    }
    static GroupAuthorizationException* new0()
    {
        return new GroupAuthorizationException();
    }
};

#endif // !__KFK_GROUPAUTHORIZATIONEXCEPTION_H__
