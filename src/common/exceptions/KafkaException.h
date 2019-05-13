#ifndef __KFK_KAFKAEXCEPTION_H__
#define __KFK_KAFKAEXCEPTION_H__

#pragma once
#include "Object.h"
#include <string>

class KafkaException
    : public Object
{
public:
    KafkaException(std::string message);
    virtual ~KafkaException()
    {

    }

    virtual std::string toString()
    {
        return message_;
    }

protected:
    std::string message_;
};

#endif // !__KFK_KAFKAEXCEPTION_H__
