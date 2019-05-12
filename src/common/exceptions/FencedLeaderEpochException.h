#ifndef __KFK_FENCEDLEADEREPOCHEXCEPTION_H__
#define __KFK_FENCEDLEADEREPOCHEXCEPTION_H__

#pragma once
#include "ApiException.h"

class FencedLeaderEpochException
    : public ApiException
{
public:
    FencedLeaderEpochException() : ApiException("") {}
    FencedLeaderEpochException(std::string message);
    virtual ~FencedLeaderEpochException()
    {

    }
    static FencedLeaderEpochException* new0()
    {
        return new FencedLeaderEpochException();
    }
};

#endif // !__KFK_FENCEDLEADEREPOCHEXCEPTION_H__
