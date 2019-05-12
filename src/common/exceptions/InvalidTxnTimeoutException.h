#ifndef __KFK_INVALIDTXNTIMEOUTEXCEPTION_H__
#define __KFK_INVALIDTXNTIMEOUTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidTxnTimeoutException
    : public ApiException
{
public:
    InvalidTxnTimeoutException() : ApiException("") {}
    InvalidTxnTimeoutException(std::string message);
    virtual ~InvalidTxnTimeoutException()
    {

    }
    static InvalidTxnTimeoutException* new0()
    {
        return new InvalidTxnTimeoutException();
    }
};

#endif // !__KFK_INVALIDTXNTIMEOUTEXCEPTION_H__
