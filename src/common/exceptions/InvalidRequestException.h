#ifndef __KFK_INVALIDREQUESTEXCEPTION_H__
#define __KFK_INVALIDREQUESTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidRequestException
    : public ApiException
{
public:
    InvalidRequestException() : ApiException("") {}
    InvalidRequestException(std::string message);
    virtual ~InvalidRequestException()
    {

    }
    static InvalidRequestException* new0()
    {
        return new InvalidRequestException();
    }
};

#endif // !__KFK_INVALIDREQUESTEXCEPTION_H__
