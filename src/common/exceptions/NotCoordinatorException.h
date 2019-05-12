#ifndef __KFK_NOTCOORDINATOREXCEPTION_H__
#define __KFK_NOTCOORDINATOREXCEPTION_H__

#pragma once
#include "ApiException.h"

class NotCoordinatorException
    : public ApiException
{
public:
    NotCoordinatorException() : ApiException("") {}
    NotCoordinatorException(std::string message);
    virtual ~NotCoordinatorException()
    {

    }
    static NotCoordinatorException* new0()
    {
        return new NotCoordinatorException();
    }
};

#endif // !__KFK_NOTCOORDINATOREXCEPTION_H__
