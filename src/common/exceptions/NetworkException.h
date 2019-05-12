#ifndef __KFK_NETWORKEXCEPTION_H__
#define __KFK_NETWORKEXCEPTION_H__

#pragma once
#include "ApiException.h"

class NetworkException
    : public ApiException
{
public:
    NetworkException() : ApiException("") {}
    NetworkException(std::string message);
    virtual ~NetworkException()
    {

    }
    static NetworkException* new0()
    {
        return new NetworkException();
    }
};

#endif // !__KFK_NETWORKEXCEPTION_H__
