#ifndef __KFK_RECORDBATCHTOOLARGEEXCEPTION_H__
#define __KFK_RECORDBATCHTOOLARGEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class RecordBatchTooLargeException
    : public ApiException
{
public:
    RecordBatchTooLargeException() : ApiException("") {}
    RecordBatchTooLargeException(std::string message);
    virtual ~RecordBatchTooLargeException()
    {

    }
    static RecordBatchTooLargeException* new0()
    {
        return new RecordBatchTooLargeException();
    }
};

#endif // !__KFK_RECORDBATCHTOOLARGEEXCEPTION_H__
