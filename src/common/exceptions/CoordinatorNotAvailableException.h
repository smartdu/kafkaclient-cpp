#ifndef __KFK_COORDINATORNOTAVAILABLEEXCEPTION_H__
#define __KFK_COORDINATORNOTAVAILABLEEXCEPTION_H__

#pragma once
#include "ApiException.h"

class CoordinatorNotAvailableException
    : public ApiException
{
public:
    CoordinatorNotAvailableException() : ApiException("") {}
    CoordinatorNotAvailableException(std::string message);
    virtual ~CoordinatorNotAvailableException()
    {

    }
    static CoordinatorNotAvailableException* new0()
    {
        return new CoordinatorNotAvailableException();
    }
};

#endif // !__KFK_COORDINATORNOTAVAILABLEEXCEPTION_H__
