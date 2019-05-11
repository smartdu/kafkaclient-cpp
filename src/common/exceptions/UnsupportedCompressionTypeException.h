#ifndef __KFK_UNSUPPORTEDCOMPRESSIONTYPEEXCEPTION_H__
#define __KFK_UNSUPPORTEDCOMPRESSIONTYPEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnsupportedCompressionTypeException
    : public ApiException
{
public:
    UnsupportedCompressionTypeException() : ApiException("") {}
    UnsupportedCompressionTypeException(std::string message);
    virtual ~UnsupportedCompressionTypeException()
    {

    }
    static UnsupportedCompressionTypeException* new0()
    {
        return new UnsupportedCompressionTypeException();
    }
};

#endif // !__KFK_UNSUPPORTEDCOMPRESSIONTYPEEXCEPTION_H__
