#ifndef __KFK_UTILS_H__
#define __KFK_UTILS_H__

#pragma once
class ByteBuffer;
class String;
class ByteArray;
class ObjectArray;
#include <string>
#include <list>
#include <map>

class Utils
{
public:
	static ByteArray* utf8(String *o);

	static String* utf8(ByteBuffer *buffer, int length);

	static String* utf8(ByteBuffer *buffer);

	static String* utf8(ByteBuffer *buffer, int offset, int length);

	static int utf8Length(String *o);

	template<typename T>
	static std::string join(std::list<T> list, const char *separator)
	{
		return "";
	}

	template<typename K, typename V>
	static std::list<V> values(std::map<K, V> m)
	{
		std::list<V> l;
		for (auto &iter : m)
			l.push_back(iter.second);
		return l;
	}

	template<typename T>
	static ObjectArray* toArray(std::list<T> l)
	{
		return NULL;
	}
};

#endif // !__KFK_UTILS_H__
