#ifndef __KFK_GROUPNOTEMPTYEXCEPTION_H__
#define __KFK_GROUPNOTEMPTYEXCEPTION_H__

#pragma once
#include "ApiException.h"

class GroupNotEmptyException
    : public ApiException
{
public:
    GroupNotEmptyException() : ApiException("") {}
    GroupNotEmptyException(std::string message);
    virtual ~GroupNotEmptyException()
    {

    }
    static GroupNotEmptyException* new0()
    {
        return new GroupNotEmptyException();
    }
};

#endif // !__KFK_GROUPNOTEMPTYEXCEPTION_H__
