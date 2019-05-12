#ifndef __KFK_INVALIDFETCHSESSIONEPOCHEXCEPTION_H__
#define __KFK_INVALIDFETCHSESSIONEPOCHEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidFetchSessionEpochException
    : public ApiException
{
public:
    InvalidFetchSessionEpochException() : ApiException("") {}
    InvalidFetchSessionEpochException(std::string message);
    virtual ~InvalidFetchSessionEpochException()
    {

    }
    static InvalidFetchSessionEpochException* new0()
    {
        return new InvalidFetchSessionEpochException();
    }
};

#endif // !__KFK_INVALIDFETCHSESSIONEPOCHEXCEPTION_H__
