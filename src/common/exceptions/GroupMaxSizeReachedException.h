#ifndef __KFK_GROUPMAXSIZEREACHEDEXCEPTION_H__
#define __KFK_GROUPMAXSIZEREACHEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class GroupMaxSizeReachedException
    : public ApiException
{
public:
    GroupMaxSizeReachedException() : ApiException("") {}
    GroupMaxSizeReachedException(std::string message);
    virtual ~GroupMaxSizeReachedException()
    {

    }
    static GroupMaxSizeReachedException* new0()
    {
        return new GroupMaxSizeReachedException();
    }
};

#endif // !__KFK_GROUPMAXSIZEREACHEDEXCEPTION_H__
