#ifndef __KFK_FETCHSESSIONIDNOTFOUNDEXCEPTION_H__
#define __KFK_FETCHSESSIONIDNOTFOUNDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class FetchSessionIdNotFoundException
    : public ApiException
{
public:
    FetchSessionIdNotFoundException() : ApiException("") {}
    FetchSessionIdNotFoundException(std::string message);
    virtual ~FetchSessionIdNotFoundException()
    {

    }
    static FetchSessionIdNotFoundException* new0()
    {
        return new FetchSessionIdNotFoundException();
    }
};

#endif // !__KFK_FETCHSESSIONIDNOTFOUNDEXCEPTION_H__
