#ifndef __KFK_REBALANCEINPROGRESSEXCEPTION_H__
#define __KFK_REBALANCEINPROGRESSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class RebalanceInProgressException
    : public ApiException
{
public:
    RebalanceInProgressException() : ApiException("") {}
    RebalanceInProgressException(std::string message);
    virtual ~RebalanceInProgressException()
    {

    }
    static RebalanceInProgressException* new0()
    {
        return new RebalanceInProgressException();
    }
};

#endif // !__KFK_REBALANCEINPROGRESSEXCEPTION_H__
