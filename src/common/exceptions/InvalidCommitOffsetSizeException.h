#ifndef __KFK_INVALIDCOMMITOFFSETSIZEEXCEPTION_H__
#define __KFK_INVALIDCOMMITOFFSETSIZEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidCommitOffsetSizeException
    : public ApiException
{
public:
    InvalidCommitOffsetSizeException() : ApiException("") {}
    InvalidCommitOffsetSizeException(std::string message);
    virtual ~InvalidCommitOffsetSizeException()
    {

    }
    static InvalidCommitOffsetSizeException* new0()
    {
        return new InvalidCommitOffsetSizeException();
    }
};

#endif // !__KFK_INVALIDCOMMITOFFSETSIZEEXCEPTION_H__
