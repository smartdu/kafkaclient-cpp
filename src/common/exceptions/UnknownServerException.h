#ifndef __KFK_UNKNOWNSERVEREXCEPTION_H__
#define __KFK_UNKNOWNSERVEREXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnknownServerException
    : public ApiException
{
public:
    UnknownServerException() : ApiException("") {}
    UnknownServerException(std::string message);
    virtual ~UnknownServerException()
    {

    }
    static UnknownServerException* new0()
    {
        return new UnknownServerException();
    }
};

#endif // !__KFK_UNKNOWNSERVEREXCEPTION_H__
