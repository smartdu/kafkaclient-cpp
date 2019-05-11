#ifndef __KFK_ILLEGALGENERATIONEXCEPTION_H__
#define __KFK_ILLEGALGENERATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class IllegalGenerationException
    : public ApiException
{
public:
    IllegalGenerationException() : ApiException("") {}
    IllegalGenerationException(std::string message);
    virtual ~IllegalGenerationException()
    {

    }
    static IllegalGenerationException* new0()
    {
        return new IllegalGenerationException();
    }
};

#endif // !__KFK_ILLEGALGENERATIONEXCEPTION_H__
