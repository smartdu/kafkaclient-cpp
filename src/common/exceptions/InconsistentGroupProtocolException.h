#ifndef __KFK_INCONSISTENTGROUPPROTOCOLEXCEPTION_H__
#define __KFK_INCONSISTENTGROUPPROTOCOLEXCEPTION_H__

#pragma once
#include "ApiException.h"

class InconsistentGroupProtocolException
    : public ApiException
{
public:
    InconsistentGroupProtocolException() : ApiException("") {}
    InconsistentGroupProtocolException(std::string message);
    virtual ~InconsistentGroupProtocolException()
    {

    }
    static InconsistentGroupProtocolException* new0()
    {
        return new InconsistentGroupProtocolException();
    }
};

#endif // !__KFK_INCONSISTENTGROUPPROTOCOLEXCEPTION_H__
