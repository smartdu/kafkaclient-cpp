#ifndef __KFK_UNKNOWNLEADEREPOCHEXCEPTION_H__
#define __KFK_UNKNOWNLEADEREPOCHEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnknownLeaderEpochException
    : public ApiException
{
public:
    UnknownLeaderEpochException() : ApiException("") {}
    UnknownLeaderEpochException(std::string message);
    virtual ~UnknownLeaderEpochException()
    {

    }
    static UnknownLeaderEpochException* new0()
    {
        return new UnknownLeaderEpochException();
    }
};

#endif // !__KFK_UNKNOWNLEADEREPOCHEXCEPTION_H__
