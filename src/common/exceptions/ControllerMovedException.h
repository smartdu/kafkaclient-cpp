#ifndef __KFK_CONTROLLERMOVEDEXCEPTION_H__
#define __KFK_CONTROLLERMOVEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ControllerMovedException
    : public ApiException
{
public:
    ControllerMovedException() : ApiException("") {}
    ControllerMovedException(std::string message);
    virtual ~ControllerMovedException()
    {

    }
    static ControllerMovedException* new0()
    {
        return new ControllerMovedException();
    }
};

#endif // !__KFK_CONTROLLERMOVEDEXCEPTION_H__
