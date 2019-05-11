#ifndef __KFK_SECURITYDISABLEDEXCEPTION_H__
#define __KFK_SECURITYDISABLEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class SecurityDisabledException
    : public ApiException
{
public:
    SecurityDisabledException() : ApiException("") {}
    SecurityDisabledException(std::string message);
    virtual ~SecurityDisabledException()
    {

    }
    static SecurityDisabledException* new0()
    {
        return new SecurityDisabledException();
    }
};

#endif // !__KFK_SECURITYDISABLEDEXCEPTION_H__
