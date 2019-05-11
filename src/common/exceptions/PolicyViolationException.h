#ifndef __KFK_POLICYVIOLATIONEXCEPTION_H__
#define __KFK_POLICYVIOLATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class PolicyViolationException
    : public ApiException
{
public:
    PolicyViolationException() : ApiException("") {}
    PolicyViolationException(std::string message);
    virtual ~PolicyViolationException()
    {

    }
    static PolicyViolationException* new0()
    {
        return new PolicyViolationException();
    }
};

#endif // !__KFK_POLICYVIOLATIONEXCEPTION_H__
