#include "Errors.h"
#include <stdio.h>

static std::map<short, Errors*> codeToError = std::map<short, Errors*>();

Errors* Errors::UNKNOWN_SERVER_ERROR = new Errors(-1, "The server experienced an unexpected error when processing the request.");
Errors* Errors::NONE = new Errors(0, NULL);

Errors::Errors(int code, const char *defaultExceptionString)
{
	this->code_ = code;
	codeToError[code] = this;
}

Errors* Errors::forCode(short code)
{
	Errors *error = codeToError[code];
	if (error != NULL)
	{
		return error;
	}
	else
	{
		return UNKNOWN_SERVER_ERROR;
	}
}

short Errors::code()
{
	return code_;
}