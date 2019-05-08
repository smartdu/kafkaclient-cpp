#ifndef __KFK_ARRAYOF_H__
#define __KFK_ARRAYOF_H__

#pragma once
class ObjectArray;
class Type;
class Object;
#include "Type.h"

class ArrayOf
	: public DocumentedType
{
public:
	ArrayOf(Type *type);
	ArrayOf(Type *type, bool nullable);

	static ArrayOf* nullable(Type *type);

	virtual bool isNullable();

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual Type* type();

	virtual std::string toString();

	virtual Object* validate(Object *item);

	virtual std::string typeName();

	virtual std::string documentation();

private:
	static const char *ARRAY_TYPE_NAME;
	Type *type_;
	bool nullable_;
};

#endif // !__KFK_ARRAYOF_H__
