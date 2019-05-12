#ifndef __KFK_NOTLEADERFORPARTITIONEXCEPTION_H__
#define __KFK_NOTLEADERFORPARTITIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class NotLeaderForPartitionException
    : public ApiException
{
public:
    NotLeaderForPartitionException() : ApiException("") {}
    NotLeaderForPartitionException(std::string message);
    virtual ~NotLeaderForPartitionException()
    {

    }
    static NotLeaderForPartitionException* new0()
    {
        return new NotLeaderForPartitionException();
    }
};

#endif // !__KFK_NOTLEADERFORPARTITIONEXCEPTION_H__
