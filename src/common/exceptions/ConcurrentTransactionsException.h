#ifndef __KFK_CONCURRENTTRANSACTIONSEXCEPTION_H__
#define __KFK_CONCURRENTTRANSACTIONSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ConcurrentTransactionsException
    : public ApiException
{
public:
    ConcurrentTransactionsException() : ApiException("") {}
    ConcurrentTransactionsException(std::string message);
    virtual ~ConcurrentTransactionsException()
    {

    }
    static ConcurrentTransactionsException* new0()
    {
        return new ConcurrentTransactionsException();
    }
};

#endif // !__KFK_CONCURRENTTRANSACTIONSEXCEPTION_H__
