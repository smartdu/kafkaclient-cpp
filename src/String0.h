#ifndef __KFK_STRING_H__
#define __KFK_STRING_H__

#pragma once
#include "Object.h"

class String
	: public Object
{
public:
	String(const char *value);
	String(std::string &value);
	virtual ~String()
	{

	}

	operator std::string&()
	{
		return value_;
	}

	operator const char*()
	{
		return value_.c_str();
	}

	operator int()
	{
		return value_.size();
	}

private:
	std::string value_;
};

#endif // !__KFK_STRING_H__
