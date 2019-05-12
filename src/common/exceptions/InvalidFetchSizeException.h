#ifndef __KFK_INVALIDFETCHSIZEEXCEPTION_H__
#define __KFK_INVALIDFETCHSIZEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidFetchSizeException
    : public ApiException
{
public:
    InvalidFetchSizeException() : ApiException("") {}
    InvalidFetchSizeException(std::string message);
    virtual ~InvalidFetchSizeException()
    {

    }
    static InvalidFetchSizeException* new0()
    {
        return new InvalidFetchSizeException();
    }
};

#endif // !__KFK_INVALIDFETCHSIZEEXCEPTION_H__
