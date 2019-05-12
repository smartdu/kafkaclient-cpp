#ifndef __KFK_OFFSETMETADATATOOLARGE_H__
#define __KFK_OFFSETMETADATATOOLARGE_H__

#pragma once
#include "ApiException.h"

class OffsetMetadataTooLarge
    : public ApiException
{
public:
    OffsetMetadataTooLarge() : ApiException("") {}
    OffsetMetadataTooLarge(std::string message);
    virtual ~OffsetMetadataTooLarge()
    {

    }
    static OffsetMetadataTooLarge* new0()
    {
        return new OffsetMetadataTooLarge();
    }
};

#endif // !__KFK_OFFSETMETADATATOOLARGE_H__
