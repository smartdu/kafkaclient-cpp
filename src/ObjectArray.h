#ifndef __KFK_OBJECTARRAY_H__
#define __KFK_OBJECTARRAY_H__

#pragma once
#include "Object.h"

class ObjectArray
	: public Object
{
public:
	int length;
	Object **obj;

	Object*& operator[](int index)
	{
		return obj[index];
	}

	operator int()
	{
		return length;
	}

	ObjectArray(int size);
	virtual ~ObjectArray();
};

#endif // !__KFK_OBJECTARRAY_H__
