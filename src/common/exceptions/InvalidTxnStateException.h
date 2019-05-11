#ifndef __KFK_INVALIDTXNSTATEEXCEPTION_H__
#define __KFK_INVALIDTXNSTATEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidTxnStateException
    : public ApiException
{
public:
    InvalidTxnStateException() : ApiException("") {}
    InvalidTxnStateException(std::string message);
    virtual ~InvalidTxnStateException()
    {

    }
    static InvalidTxnStateException* new0()
    {
        return new InvalidTxnStateException();
    }
};

#endif // !__KFK_INVALIDTXNSTATEEXCEPTION_H__
