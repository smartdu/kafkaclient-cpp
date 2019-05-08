#ifndef __KFK_BOOLEAN_H__
#define __KFK_BOOLEAN_H__

#pragma once
#include "Object.h"

class Boolean
	: public Object
{
public:
	Boolean(bool value);

	operator bool()
	{
		return value_;
	}

private:
	bool value_;
};

#endif // !__KFK_BOOLEAN_H__
