#ifndef __KFK_TOPICEXISTSEXCEPTION_H__
#define __KFK_TOPICEXISTSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TopicExistsException
    : public ApiException
{
public:
    TopicExistsException() : ApiException("") {}
    TopicExistsException(std::string message);
    virtual ~TopicExistsException()
    {

    }
    static TopicExistsException* new0()
    {
        return new TopicExistsException();
    }
};

#endif // !__KFK_TOPICEXISTSEXCEPTION_H__
