#ifndef __KFK_INVALIDREPLICATIONFACTOREXCEPTION_H__
#define __KFK_INVALIDREPLICATIONFACTOREXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidReplicationFactorException
    : public ApiException
{
public:
    InvalidReplicationFactorException() : ApiException("") {}
    InvalidReplicationFactorException(std::string message);
    virtual ~InvalidReplicationFactorException()
    {

    }
    static InvalidReplicationFactorException* new0()
    {
        return new InvalidReplicationFactorException();
    }
};

#endif // !__KFK_INVALIDREPLICATIONFACTOREXCEPTION_H__
