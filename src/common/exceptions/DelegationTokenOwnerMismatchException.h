#ifndef __KFK_DELEGATIONTOKENOWNERMISMATCHEXCEPTION_H__
#define __KFK_DELEGATIONTOKENOWNERMISMATCHEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DelegationTokenOwnerMismatchException
    : public ApiException
{
public:
    DelegationTokenOwnerMismatchException() : ApiException("") {}
    DelegationTokenOwnerMismatchException(std::string message);
    virtual ~DelegationTokenOwnerMismatchException()
    {

    }
    static DelegationTokenOwnerMismatchException* new0()
    {
        return new DelegationTokenOwnerMismatchException();
    }
};

#endif // !__KFK_DELEGATIONTOKENOWNERMISMATCHEXCEPTION_H__
