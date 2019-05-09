#ifndef __KFK_UTILS_H__
#define __KFK_UTILS_H__

#pragma once
class ByteBuffer;
class String;
class ByteArray;

class Utils
{
public:
	static ByteArray* utf8(String *o);

	static String* utf8(ByteBuffer *buffer, int length);

	static int utf8Length(String *o);

	template<typename T>
	static std::string join(std::list<T, std::allocator<T>> list, const char *separator);
};

#endif // !__KFK_UTILS_H__
