#ifndef __KFK_DELEGATIONTOKENDISABLEDEXCEPTION_H__
#define __KFK_DELEGATIONTOKENDISABLEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DelegationTokenDisabledException
    : public ApiException
{
public:
    DelegationTokenDisabledException() : ApiException("") {}
    DelegationTokenDisabledException(std::string message);
    virtual ~DelegationTokenDisabledException()
    {

    }
    static DelegationTokenDisabledException* new0()
    {
        return new DelegationTokenDisabledException();
    }
};

#endif // !__KFK_DELEGATIONTOKENDISABLEDEXCEPTION_H__
