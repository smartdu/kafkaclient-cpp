#ifndef __KFK_INVALIDCONFIGURATIONEXCEPTION_H__
#define __KFK_INVALIDCONFIGURATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidConfigurationException
    : public ApiException
{
public:
    InvalidConfigurationException() : ApiException("") {}
    InvalidConfigurationException(std::string message);
    virtual ~InvalidConfigurationException()
    {

    }
    static InvalidConfigurationException* new0()
    {
        return new InvalidConfigurationException();
    }
};

#endif // !__KFK_INVALIDCONFIGURATIONEXCEPTION_H__
