#ifndef __KFK_CLUSTERAUTHORIZATIONEXCEPTION_H__
#define __KFK_CLUSTERAUTHORIZATIONEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ClusterAuthorizationException
    : public ApiException
{
public:
    ClusterAuthorizationException() : ApiException("") {}
    ClusterAuthorizationException(std::string message);
    virtual ~ClusterAuthorizationException()
    {

    }
    static ClusterAuthorizationException* new0()
    {
        return new ClusterAuthorizationException();
    }
};

#endif // !__KFK_CLUSTERAUTHORIZATIONEXCEPTION_H__
