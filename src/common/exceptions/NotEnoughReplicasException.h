#ifndef __KFK_NOTENOUGHREPLICASEXCEPTION_H__
#define __KFK_NOTENOUGHREPLICASEXCEPTION_H__

#pragma once
#include "ApiException.h"

class NotEnoughReplicasException
    : public ApiException
{
public:
    NotEnoughReplicasException() : ApiException("") {}
    NotEnoughReplicasException(std::string message);
    virtual ~NotEnoughReplicasException()
    {

    }
    static NotEnoughReplicasException* new0()
    {
        return new NotEnoughReplicasException();
    }
};

#endif // !__KFK_NOTENOUGHREPLICASEXCEPTION_H__
