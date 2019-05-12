#ifndef __KFK_REPLICANOTAVAILABLEEXCEPTION_H__
#define __KFK_REPLICANOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ReplicaNotAvailableException
    : public ApiException
{
public:
    ReplicaNotAvailableException() : ApiException("") {}
    ReplicaNotAvailableException(std::string message);
    virtual ~ReplicaNotAvailableException()
    {

    }
    static ReplicaNotAvailableException* new0()
    {
        return new ReplicaNotAvailableException();
    }
};

#endif // !__KFK_REPLICANOTAVAILABLEEXCEPTION_H__
