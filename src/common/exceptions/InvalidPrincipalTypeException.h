#ifndef __KFK_INVALIDPRINCIPALTYPEEXCEPTION_H__
#define __KFK_INVALIDPRINCIPALTYPEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidPrincipalTypeException
    : public ApiException
{
public:
    InvalidPrincipalTypeException() : ApiException("") {}
    InvalidPrincipalTypeException(std::string message);
    virtual ~InvalidPrincipalTypeException()
    {

    }
    static InvalidPrincipalTypeException* new0()
    {
        return new InvalidPrincipalTypeException();
    }
};

#endif // !__KFK_INVALIDPRINCIPALTYPEEXCEPTION_H__
