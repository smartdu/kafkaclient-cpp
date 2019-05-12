#ifndef __KFK_UNSUPPORTEDFORMESSAGEFORMATEXCEPTION_H__
#define __KFK_UNSUPPORTEDFORMESSAGEFORMATEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnsupportedForMessageFormatException
    : public ApiException
{
public:
    UnsupportedForMessageFormatException() : ApiException("") {}
    UnsupportedForMessageFormatException(std::string message);
    virtual ~UnsupportedForMessageFormatException()
    {

    }
    static UnsupportedForMessageFormatException* new0()
    {
        return new UnsupportedForMessageFormatException();
    }
};

#endif // !__KFK_UNSUPPORTEDFORMESSAGEFORMATEXCEPTION_H__
