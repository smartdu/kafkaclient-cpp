#ifndef __KFK_INVALIDREPLICAASSIGNMENTEXCEPTION_H__
#define __KFK_INVALIDREPLICAASSIGNMENTEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InvalidReplicaAssignmentException
    : public ApiException
{
public:
    InvalidReplicaAssignmentException() : ApiException("") {}
    InvalidReplicaAssignmentException(std::string message);
    virtual ~InvalidReplicaAssignmentException()
    {

    }
    static InvalidReplicaAssignmentException* new0()
    {
        return new InvalidReplicaAssignmentException();
    }
};

#endif // !__KFK_INVALIDREPLICAASSIGNMENTEXCEPTION_H__
