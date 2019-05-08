#include "ByteArray.h"
#include <string>
#include "String0.h"

ByteArray::ByteArray(const char *data, int size)
{
	size_ = size;
	data_ = (char*)malloc(size);
	memcpy(data_, data, size_);
}

ByteArray::ByteArray(String *o)
{
	size_ = *o;
	data_ = (char*)malloc(size_);
	memcpy(data_, (const char*)*o, size_);
}

ByteArray::ByteArray(int size)
{
	size_ = size;
	data_ = (char*)malloc(size);
}

ByteArray::~ByteArray()
{
	if (data_ != NULL)
		free((void*)data_);
	data_ = NULL;
}
