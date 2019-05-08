#ifndef __KFK_ABSTRACTREQUEST_H__
#define __KFK_ABSTRACTREQUEST_H__

#pragma once
#include "AbstractRequestResponse.h"

class AbstractRequest
	: public AbstractRequestResponse
{
public:
	AbstractRequest();

	short version();

private:
	short version_;
};

#endif // !__KFK_ABSTRACTREQUEST_H__
