#ifndef __KFK_ABSTRACTREQUEST_H__
#define __KFK_ABSTRACTREQUEST_H__

#pragma once
#include "AbstractRequestResponse.h"
class ApiKeys;

class AbstractRequest
	: public AbstractRequestResponse
{
public:
	AbstractRequest();
    AbstractRequest(ApiKeys *api, short version);

	virtual ~AbstractRequest()
	{

	}

	short version();

private:
	short version_;
};

#endif // !__KFK_ABSTRACTREQUEST_H__
