#ifndef __KFK_ERRORS_H__
#define __KFK_ERRORS_H__

#pragma once
#include <map>

class Errors
{
public:
	static Errors* UNKNOWN_SERVER_ERROR;
	static Errors* NONE;

	Errors(int code, const char *defaultExceptionString);
	virtual ~Errors()
	{

	}

	static Errors* forCode(short code);

	short code();

private:
	short code_;
};

#endif // !__KFK_ERRORS_H__
