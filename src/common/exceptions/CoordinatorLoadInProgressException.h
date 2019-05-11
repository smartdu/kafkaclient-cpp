#ifndef __KFK_COORDINATORLOADINPROGRESSEXCEPTION_H__
#define __KFK_COORDINATORLOADINPROGRESSEXCEPTION_H__

#pragma once
#include "ApiException.h"

class CoordinatorLoadInProgressException
    : public ApiException
{
public:
    CoordinatorLoadInProgressException() : ApiException("") {}
    CoordinatorLoadInProgressException(std::string message);
    virtual ~CoordinatorLoadInProgressException()
    {

    }
    static CoordinatorLoadInProgressException* new0()
    {
        return new CoordinatorLoadInProgressException();
    }
};

#endif // !__KFK_COORDINATORLOADINPROGRESSEXCEPTION_H__
