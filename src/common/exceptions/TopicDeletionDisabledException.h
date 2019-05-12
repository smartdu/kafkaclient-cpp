#ifndef __KFK_TOPICDELETIONDISABLEDEXCEPTION_H__
#define __KFK_TOPICDELETIONDISABLEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TopicDeletionDisabledException
    : public ApiException
{
public:
    TopicDeletionDisabledException() : ApiException("") {}
    TopicDeletionDisabledException(std::string message);
    virtual ~TopicDeletionDisabledException()
    {

    }
    static TopicDeletionDisabledException* new0()
    {
        return new TopicDeletionDisabledException();
    }
};

#endif // !__KFK_TOPICDELETIONDISABLEDEXCEPTION_H__
