#include "String0.h"

String::String(const char *value)
{
	this->value_ = value;
}

String::String(std::string &value)
{
	this->value_ = value;
}