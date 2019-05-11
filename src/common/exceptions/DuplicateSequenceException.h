#ifndef __KFK_DUPLICATESEQUENCEEXCEPTION_H__
#define __KFK_DUPLICATESEQUENCEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class DuplicateSequenceException
    : public ApiException
{
public:
    DuplicateSequenceException() : ApiException("") {}
    DuplicateSequenceException(std::string message);
    virtual ~DuplicateSequenceException()
    {

    }
    static DuplicateSequenceException* new0()
    {
        return new DuplicateSequenceException();
    }
};

#endif // !__KFK_DUPLICATESEQUENCEEXCEPTION_H__
