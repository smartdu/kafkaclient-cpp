#ifndef __KFK_REASSIGNMENTINPROGRESSEXCEPTION_H__
#define __KFK_REASSIGNMENTINPROGRESSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ReassignmentInProgressException
    : public ApiException
{
public:
    ReassignmentInProgressException() : ApiException("") {}
    ReassignmentInProgressException(std::string message);
    virtual ~ReassignmentInProgressException()
    {

    }
    static ReassignmentInProgressException* new0()
    {
        return new ReassignmentInProgressException();
    }
};

#endif // !__KFK_REASSIGNMENTINPROGRESSEXCEPTION_H__
