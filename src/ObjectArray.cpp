#include "ObjectArray.h"

ObjectArray::ObjectArray(int size)
{
	length = size;
	obj = new Object*[size];
	for (int i = 0; i < size; i++)
		obj[i] = NULL;
}

ObjectArray::~ObjectArray()
{
	for (int i = 0; i < length; i++)
		if (obj[i] != NULL)
			delete obj[i];
	delete[] obj;
}