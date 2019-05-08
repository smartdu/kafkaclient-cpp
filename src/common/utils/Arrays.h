#ifndef __KFK_ARRAYS_H__
#define __KFK_ARRAYS_H__

#pragma once
class ObjectArray;
class Object;
#include <list>

class Arrays
{
public:
	static void fill(ObjectArray *array, Object *o);

	template<typename T>
	static ObjectArray* toArray(std::list<T> &l)
	{
		ObjectArray *a = new ObjectArray(l.size());

		int i = 0;
		for (auto iter : l)
		{
			(*a)[i++] = iter;
		}

		return a;
	}
};

#endif // !__KFK_ARRAYS_H__
