#ifndef __KFK_UNKNOWNTOPICORPARTITIONEXCEPTION_H__
#define __KFK_UNKNOWNTOPICORPARTITIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnknownTopicOrPartitionException
    : public ApiException
{
public:
    UnknownTopicOrPartitionException() : ApiException("") {}
    UnknownTopicOrPartitionException(std::string message);
    virtual ~UnknownTopicOrPartitionException()
    {

    }
    static UnknownTopicOrPartitionException* new0()
    {
        return new UnknownTopicOrPartitionException();
    }
};

#endif // !__KFK_UNKNOWNTOPICORPARTITIONEXCEPTION_H__
