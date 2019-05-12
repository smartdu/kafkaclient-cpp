#ifndef __KFK_LEADERNOTAVAILABLEEXCEPTION_H__
#define __KFK_LEADERNOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class LeaderNotAvailableException
    : public ApiException
{
public:
    LeaderNotAvailableException() : ApiException("") {}
    LeaderNotAvailableException(std::string message);
    virtual ~LeaderNotAvailableException()
    {

    }
    static LeaderNotAvailableException* new0()
    {
        return new LeaderNotAvailableException();
    }
};

#endif // !__KFK_LEADERNOTAVAILABLEEXCEPTION_H__
