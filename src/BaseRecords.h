#ifndef __KFK_BASERECORDS_H__
#define __KFK_BASERECORDS_H__

#pragma once

class BaseRecords
	: public Object
{
public:
	virtual int sizeInBytes() = 0;
};

#endif // !__KFK_BASERECORDS_H__
