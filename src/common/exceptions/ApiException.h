#ifndef __KFK_APIEXCEPTION_H__
#define __KFK_APIEXCEPTION_H__

#pragma once
#include "KafkaException.h"

class ApiException
    : public KafkaException
{
public:
    ApiException(std::string message);
    virtual ~ApiException()
    {

    }

    void message(const char *message)
    {
        message_ = message;
    }
};

#endif // !__KFK_APIEXCEPTION_H__
