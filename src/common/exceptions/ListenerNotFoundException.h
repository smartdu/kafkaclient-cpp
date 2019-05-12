#ifndef __KFK_LISTENERNOTFOUNDEXCEPTION_H__
#define __KFK_LISTENERNOTFOUNDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class ListenerNotFoundException
    : public ApiException
{
public:
    ListenerNotFoundException() : ApiException("") {}
    ListenerNotFoundException(std::string message);
    virtual ~ListenerNotFoundException()
    {

    }
    static ListenerNotFoundException* new0()
    {
        return new ListenerNotFoundException();
    }
};

#endif // !__KFK_LISTENERNOTFOUNDEXCEPTION_H__
