#ifndef __KFK_UNSUPPORTEDVERSIONEXCEPTION_H__
#define __KFK_UNSUPPORTEDVERSIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnsupportedVersionException
    : public ApiException
{
public:
    UnsupportedVersionException() : ApiException("") {}
    UnsupportedVersionException(std::string message);
    virtual ~UnsupportedVersionException()
    {

    }
    static UnsupportedVersionException* new0()
    {
        return new UnsupportedVersionException();
    }
};

#endif // !__KFK_UNSUPPORTEDVERSIONEXCEPTION_H__
