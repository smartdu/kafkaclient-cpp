#ifndef __KFK_BYTEARRAY_H__
#define __KFK_BYTEARRAY_H__

#pragma once
class String;

class ByteArray
{
public:
	ByteArray(const char *data, int size);
	ByteArray(String *o);
	ByteArray(int size);
	virtual ~ByteArray();

	operator int()
	{
		return size_;
	}

	operator char*()
	{
		return data_;
	}

	char& operator[](int index)
	{
		return data_[index];
	}

private:
	char *data_;
	int size_;
};

#endif // !__KFK_BYTEARRAY_H__
