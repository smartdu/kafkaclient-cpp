#ifndef __KFK_INVALIDREQUIREDACKSEXCEPTION_H__
#define __KFK_INVALIDREQUIREDACKSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidRequiredAcksException
    : public ApiException
{
public:
    InvalidRequiredAcksException() : ApiException("") {}
    InvalidRequiredAcksException(std::string message);
    virtual ~InvalidRequiredAcksException()
    {

    }
    static InvalidRequiredAcksException* new0()
    {
        return new InvalidRequiredAcksException();
    }
};

#endif // !__KFK_INVALIDREQUIREDACKSEXCEPTION_H__
