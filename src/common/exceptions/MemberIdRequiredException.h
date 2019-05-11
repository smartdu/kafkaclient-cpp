#ifndef __KFK_MEMBERIDREQUIREDEXCEPTION_H__
#define __KFK_MEMBERIDREQUIREDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class MemberIdRequiredException
    : public ApiException
{
public:
    MemberIdRequiredException() : ApiException("") {}
    MemberIdRequiredException(std::string message);
    virtual ~MemberIdRequiredException()
    {

    }
    static MemberIdRequiredException* new0()
    {
        return new MemberIdRequiredException();
    }
};

#endif // !__KFK_MEMBERIDREQUIREDEXCEPTION_H__
