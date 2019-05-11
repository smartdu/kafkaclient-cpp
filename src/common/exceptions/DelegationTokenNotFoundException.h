#ifndef __KFK_DELEGATIONTOKENNOTFOUNDEXCEPTION_H__
#define __KFK_DELEGATIONTOKENNOTFOUNDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DelegationTokenNotFoundException
    : public ApiException
{
public:
    DelegationTokenNotFoundException() : ApiException("") {}
    DelegationTokenNotFoundException(std::string message);
    virtual ~DelegationTokenNotFoundException()
    {

    }
    static DelegationTokenNotFoundException* new0()
    {
        return new DelegationTokenNotFoundException();
    }
};

#endif // !__KFK_DELEGATIONTOKENNOTFOUNDEXCEPTION_H__
