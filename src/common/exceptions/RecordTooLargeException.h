#ifndef __KFK_RECORDTOOLARGEEXCEPTION_H__
#define __KFK_RECORDTOOLARGEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class RecordTooLargeException
    : public ApiException
{
public:
    RecordTooLargeException() : ApiException("") {}
    RecordTooLargeException(std::string message);
    virtual ~RecordTooLargeException()
    {

    }
    static RecordTooLargeException* new0()
    {
        return new RecordTooLargeException();
    }
};

#endif // !__KFK_RECORDTOOLARGEEXCEPTION_H__
