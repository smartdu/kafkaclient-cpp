#ifndef __KFK_OFFSETNOTAVAILABLEEXCEPTION_H__
#define __KFK_OFFSETNOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class OffsetNotAvailableException
    : public ApiException
{
public:
    OffsetNotAvailableException() : ApiException("") {}
    OffsetNotAvailableException(std::string message);
    virtual ~OffsetNotAvailableException()
    {

    }
    static OffsetNotAvailableException* new0()
    {
        return new OffsetNotAvailableException();
    }
};

#endif // !__KFK_OFFSETNOTAVAILABLEEXCEPTION_H__
