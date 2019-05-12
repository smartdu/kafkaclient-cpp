#ifndef __KFK_LONG_H__
#define __KFK_LONG_H__

#pragma once
#include "Object.h"

class Long
	: public Object
{
public:
	Long(long long value);
	virtual ~Long()
	{

	}

	operator long long()
	{
		return value_;
	}

private:
	long long value_;
};

#endif // !__KFK_LONG_H__
