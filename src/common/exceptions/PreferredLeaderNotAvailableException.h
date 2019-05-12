#ifndef __KFK_PREFERREDLEADERNOTAVAILABLEEXCEPTION_H__
#define __KFK_PREFERREDLEADERNOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class PreferredLeaderNotAvailableException
    : public ApiException
{
public:
    PreferredLeaderNotAvailableException() : ApiException("") {}
    PreferredLeaderNotAvailableException(std::string message);
    virtual ~PreferredLeaderNotAvailableException()
    {

    }
    static PreferredLeaderNotAvailableException* new0()
    {
        return new PreferredLeaderNotAvailableException();
    }
};

#endif // !__KFK_PREFERREDLEADERNOTAVAILABLEEXCEPTION_H__
