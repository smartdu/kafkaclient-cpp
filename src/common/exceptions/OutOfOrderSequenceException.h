#ifndef __KFK_OUTOFORDERSEQUENCEEXCEPTION_H__
#define __KFK_OUTOFORDERSEQUENCEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class OutOfOrderSequenceException
    : public ApiException
{
public:
    OutOfOrderSequenceException() : ApiException("") {}
    OutOfOrderSequenceException(std::string message);
    virtual ~OutOfOrderSequenceException()
    {

    }
    static OutOfOrderSequenceException* new0()
    {
        return new OutOfOrderSequenceException();
    }
};

#endif // !__KFK_OUTOFORDERSEQUENCEEXCEPTION_H__
