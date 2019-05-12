#ifndef __KFK_INVALIDMETADATAEXCEPTION_H__
#define __KFK_INVALIDMETADATAEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidMetadataException
    : public ApiException
{
public:
    InvalidMetadataException() : ApiException("") {}
    InvalidMetadataException(std::string message);
    virtual ~InvalidMetadataException()
    {

    }
    static InvalidMetadataException* new0()
    {
        return new InvalidMetadataException();
    }
};

#endif // !__KFK_INVALIDMETADATAEXCEPTION_H__
