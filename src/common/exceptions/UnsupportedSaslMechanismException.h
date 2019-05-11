#ifndef __KFK_UNSUPPORTEDSASLMECHANISMEXCEPTION_H__
#define __KFK_UNSUPPORTEDSASLMECHANISMEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnsupportedSaslMechanismException
    : public ApiException
{
public:
    UnsupportedSaslMechanismException() : ApiException("") {}
    UnsupportedSaslMechanismException(std::string message);
    virtual ~UnsupportedSaslMechanismException()
    {

    }
    static UnsupportedSaslMechanismException* new0()
    {
        return new UnsupportedSaslMechanismException();
    }
};

#endif // !__KFK_UNSUPPORTEDSASLMECHANISMEXCEPTION_H__
