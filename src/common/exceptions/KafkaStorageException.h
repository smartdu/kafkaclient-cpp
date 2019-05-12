#ifndef __KFK_KAFKASTORAGEEXCEPTION_H__
#define __KFK_KAFKASTORAGEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class KafkaStorageException
    : public ApiException
{
public:
    KafkaStorageException() : ApiException("") {}
    KafkaStorageException(std::string message);
    virtual ~KafkaStorageException()
    {

    }
    static KafkaStorageException* new0()
    {
        return new KafkaStorageException();
    }
};

#endif // !__KFK_KAFKASTORAGEEXCEPTION_H__
