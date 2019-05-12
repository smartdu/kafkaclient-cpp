#ifndef __KFK_INTEGER_H__
#define __KFK_INTEGER_H__

#pragma once
#include "Object.h"

class Integer
	: public Object
{
public:
	Integer(int value);
	virtual ~Integer()
	{

	}

	operator int()
	{
		return value_;
	}

private:
	int value_;
};

#endif // !__KFK_INTEGER_H__
