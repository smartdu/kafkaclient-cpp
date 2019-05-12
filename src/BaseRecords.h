#ifndef __KFK_BASERECORDS_H__
#define __KFK_BASERECORDS_H__

#pragma once
#include "Object.h"

class BaseRecords
	: public Object
{
public:
	virtual ~BaseRecords()
	{

	}

	virtual int sizeInBytes() = 0;
};

#endif // !__KFK_BASERECORDS_H__
