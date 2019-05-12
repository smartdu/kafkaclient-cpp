#ifndef __KFK_GROUPIDNOTFOUNDEXCEPTION_H__
#define __KFK_GROUPIDNOTFOUNDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class GroupIdNotFoundException
    : public ApiException
{
public:
    GroupIdNotFoundException() : ApiException("") {}
    GroupIdNotFoundException(std::string message);
    virtual ~GroupIdNotFoundException()
    {

    }
    static GroupIdNotFoundException* new0()
    {
        return new GroupIdNotFoundException();
    }
};

#endif // !__KFK_GROUPIDNOTFOUNDEXCEPTION_H__
