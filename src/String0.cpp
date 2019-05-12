#include "String0.h"

String::String(char *bytes, int offset, int length)
{
	for (int i = offset; i < offset + length; i++)
		this->value_.insert(this->value_.end(), bytes[i]);
}

String::String(const char *value)
{
	if (value != NULL)
		this->value_ = value;
}

String::String(std::string &value)
{
	this->value_ = value;
}