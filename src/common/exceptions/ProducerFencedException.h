#ifndef __KFK_PRODUCERFENCEDEXCEPTION_H__
#define __KFK_PRODUCERFENCEDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ProducerFencedException
    : public ApiException
{
public:
    ProducerFencedException() : ApiException("") {}
    ProducerFencedException(std::string message);
    virtual ~ProducerFencedException()
    {

    }
    static ProducerFencedException* new0()
    {
        return new ProducerFencedException();
    }
};

#endif // !__KFK_PRODUCERFENCEDEXCEPTION_H__
