#ifndef __KFK_TOPICAUTHORIZATIONEXCEPTION_H__
#define __KFK_TOPICAUTHORIZATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TopicAuthorizationException
    : public ApiException
{
public:
    TopicAuthorizationException() : ApiException("") {}
    TopicAuthorizationException(std::string message);
    virtual ~TopicAuthorizationException()
    {

    }
    static TopicAuthorizationException* new0()
    {
        return new TopicAuthorizationException();
    }
};

#endif // !__KFK_TOPICAUTHORIZATIONEXCEPTION_H__
