#ifndef __KFK_STALEBROKEREPOCHEXCEPTION_H__
#define __KFK_STALEBROKEREPOCHEXCEPTION_H__

#pragma once
#include "ApiException.h"

class StaleBrokerEpochException
    : public ApiException
{
public:
    StaleBrokerEpochException() : ApiException("") {}
    StaleBrokerEpochException(std::string message);
    virtual ~StaleBrokerEpochException()
    {

    }
    static StaleBrokerEpochException* new0()
    {
        return new StaleBrokerEpochException();
    }
};

#endif // !__KFK_STALEBROKEREPOCHEXCEPTION_H__
