#ifndef __KFK_BYTE_H__
#define __KFK_BYTE_H__

#pragma once
#include "Object.h"

class Byte
	: public Object
{
public:
	Byte(char value);

	operator char()
	{
		return value_;
	}

private:
	char value_;
};

#endif // !__KFK_BYTE_H__
