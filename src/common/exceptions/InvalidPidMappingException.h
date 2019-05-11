#ifndef __KFK_INVALIDPIDMAPPINGEXCEPTION_H__
#define __KFK_INVALIDPIDMAPPINGEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidPidMappingException
    : public ApiException
{
public:
    InvalidPidMappingException() : ApiException("") {}
    InvalidPidMappingException(std::string message);
    virtual ~InvalidPidMappingException()
    {

    }
    static InvalidPidMappingException* new0()
    {
        return new InvalidPidMappingException();
    }
};

#endif // !__KFK_INVALIDPIDMAPPINGEXCEPTION_H__
