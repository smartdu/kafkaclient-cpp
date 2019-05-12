#ifndef __KFK_UNKNOWNPRODUCERIDEXCEPTION_H__
#define __KFK_UNKNOWNPRODUCERIDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnknownProducerIdException
    : public ApiException
{
public:
    UnknownProducerIdException() : ApiException("") {}
    UnknownProducerIdException(std::string message);
    virtual ~UnknownProducerIdException()
    {

    }
    static UnknownProducerIdException* new0()
    {
        return new UnknownProducerIdException();
    }
};

#endif // !__KFK_UNKNOWNPRODUCERIDEXCEPTION_H__
