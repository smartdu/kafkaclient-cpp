#ifndef __KFK_UNKNOWNMEMBERIDEXCEPTION_H__
#define __KFK_UNKNOWNMEMBERIDEXCEPTION_H__

#pragma once
#include "ApiException.h"

class UnknownMemberIdException
    : public ApiException
{
public:
    UnknownMemberIdException() : ApiException("") {}
    UnknownMemberIdException(std::string message);
    virtual ~UnknownMemberIdException()
    {

    }
    static UnknownMemberIdException* new0()
    {
        return new UnknownMemberIdException();
    }
};

#endif // !__KFK_UNKNOWNMEMBERIDEXCEPTION_H__
