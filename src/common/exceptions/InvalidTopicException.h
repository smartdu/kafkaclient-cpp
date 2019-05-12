#ifndef __KFK_INVALIDTOPICEXCEPTION_H__
#define __KFK_INVALIDTOPICEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidTopicException
    : public ApiException
{
public:
    InvalidTopicException() : ApiException("") {}
    InvalidTopicException(std::string message);
    virtual ~InvalidTopicException()
    {

    }
    static InvalidTopicException* new0()
    {
        return new InvalidTopicException();
    }
};

#endif // !__KFK_INVALIDTOPICEXCEPTION_H__
