#ifndef __KFK_NOTCONTROLLEREXCEPTION_H__
#define __KFK_NOTCONTROLLEREXCEPTION_H__

#pragma once
#include "ApiException.h"

class NotControllerException
    : public ApiException
{
public:
    NotControllerException() : ApiException("") {}
    NotControllerException(std::string message);
    virtual ~NotControllerException()
    {

    }
    static NotControllerException* new0()
    {
        return new NotControllerException();
    }
};

#endif // !__KFK_NOTCONTROLLEREXCEPTION_H__
