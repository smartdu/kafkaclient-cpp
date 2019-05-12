#ifndef __KFK_TRANSACTIONCOORDINATORFENCEDEXCEPTION_H__
#define __KFK_TRANSACTIONCOORDINATORFENCEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class TransactionCoordinatorFencedException
    : public ApiException
{
public:
    TransactionCoordinatorFencedException() : ApiException("") {}
    TransactionCoordinatorFencedException(std::string message);
    virtual ~TransactionCoordinatorFencedException()
    {

    }
    static TransactionCoordinatorFencedException* new0()
    {
        return new TransactionCoordinatorFencedException();
    }
};

#endif // !__KFK_TRANSACTIONCOORDINATORFENCEDEXCEPTION_H__
