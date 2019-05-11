#ifndef __KFK_TRANSACTIONALIDAUTHORIZATIONEXCEPTION_H__
#define __KFK_TRANSACTIONALIDAUTHORIZATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TransactionalIdAuthorizationException
    : public ApiException
{
public:
    TransactionalIdAuthorizationException() : ApiException("") {}
    TransactionalIdAuthorizationException(std::string message);
    virtual ~TransactionalIdAuthorizationException()
    {

    }
    static TransactionalIdAuthorizationException* new0()
    {
        return new TransactionalIdAuthorizationException();
    }
};

#endif // !__KFK_TRANSACTIONALIDAUTHORIZATIONEXCEPTION_H__
