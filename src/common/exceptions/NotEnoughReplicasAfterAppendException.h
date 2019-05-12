#ifndef __KFK_NOTENOUGHREPLICASAFTERAPPENDEXCEPTION_H__
#define __KFK_NOTENOUGHREPLICASAFTERAPPENDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class NotEnoughReplicasAfterAppendException
    : public ApiException
{
public:
    NotEnoughReplicasAfterAppendException() : ApiException("") {}
    NotEnoughReplicasAfterAppendException(std::string message);
    virtual ~NotEnoughReplicasAfterAppendException()
    {

    }
    static NotEnoughReplicasAfterAppendException* new0()
    {
        return new NotEnoughReplicasAfterAppendException();
    }
};

#endif // !__KFK_NOTENOUGHREPLICASAFTERAPPENDEXCEPTION_H__
