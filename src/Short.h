#ifndef __KFK_SHORT_H__
#define __KFK_SHORT_H__

#pragma once
#include "Object.h"

class Short
	: public Object
{
public:
	static const int MAX_VALUE = 32767;
	Short(short value);

	operator short()
	{
		return value_;
	}

private:
	short value_;
};

#endif // !__KFK_SHORT_H__
