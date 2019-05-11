#ifndef __KFK_BROKERNOTAVAILABLEEXCEPTION_H__
#define __KFK_BROKERNOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class BrokerNotAvailableException
    : public ApiException
{
public:
    BrokerNotAvailableException() : ApiException("") {}
    BrokerNotAvailableException(std::string message);
    virtual ~BrokerNotAvailableException()
    {

    }
    static BrokerNotAvailableException* new0()
    {
        return new BrokerNotAvailableException();
    }
};

#endif // !__KFK_BROKERNOTAVAILABLEEXCEPTION_H__
