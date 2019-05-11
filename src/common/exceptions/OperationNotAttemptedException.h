#ifndef __KFK_OPERATIONNOTATTEMPTEDEXCEPTION_H__
#define __KFK_OPERATIONNOTATTEMPTEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class OperationNotAttemptedException
    : public ApiException
{
public:
    OperationNotAttemptedException() : ApiException("") {}
    OperationNotAttemptedException(std::string message);
    virtual ~OperationNotAttemptedException()
    {

    }
    static OperationNotAttemptedException* new0()
    {
        return new OperationNotAttemptedException();
    }
};

#endif // !__KFK_OPERATIONNOTATTEMPTEDEXCEPTION_H__
