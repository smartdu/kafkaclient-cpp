#ifndef __KFK_ILLEGALSASLSTATEEXCEPTION_H__
#define __KFK_ILLEGALSASLSTATEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class IllegalSaslStateException
    : public ApiException
{
public:
    IllegalSaslStateException() : ApiException("") {}
    IllegalSaslStateException(std::string message);
    virtual ~IllegalSaslStateException()
    {

    }
    static IllegalSaslStateException* new0()
    {
        return new IllegalSaslStateException();
    }
};

#endif // !__KFK_ILLEGALSASLSTATEEXCEPTION_H__
