#ifndef __KFK_CORRUPTRECORDEXCEPTION_H__
#define __KFK_CORRUPTRECORDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class CorruptRecordException
    : public ApiException
{
public:
    CorruptRecordException() : ApiException("") {}
    CorruptRecordException(std::string message);
    virtual ~CorruptRecordException()
    {

    }
    static CorruptRecordException* new0()
    {
        return new CorruptRecordException();
    }
};

#endif // !__KFK_CORRUPTRECORDEXCEPTION_H__
