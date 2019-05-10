#include "ArrayOf.h"
#include "ByteBuffer.h"
#include "ObjectArray.h"
#include "SchemaException.h"
#include "Object.h"
#include "Type.h"

const char* ArrayOf::ARRAY_TYPE_NAME = "ARRAY";

ArrayOf::ArrayOf(Type *type)
{
	this->type_ = type;
	this->nullable_ = false;
}

ArrayOf::ArrayOf(Type *type, bool nullable)
{
	this->type_ = type;
	this->nullable_ = nullable;
}

ArrayOf* ArrayOf::nullable(Type *type)
{
	return new ArrayOf(type, true);
}

bool ArrayOf::isNullable()
{
	return nullable_;
}

void ArrayOf::write(ByteBuffer *buffer, Object *o)
{
	if (o == NULL)
	{
		buffer->putInt(-1);
		return;
	}

	ObjectArray *objs = (ObjectArray*) o;
	int size = *objs;
	buffer->putInt(size);

	for (int i = 0; i < size; i++)
	{
		type_->write(buffer, (*objs)[i]);
	}
}

Object* ArrayOf::read(ByteBuffer *buffer)
{
	int size = buffer->getInt();
	if (size < 0 && isNullable())
		return NULL;
	else if (size < 0)
	{
		throw SchemaException("Array size " + std::to_string(size) + " cannot be negative");
	}

	if (size > buffer->remaining())
		throw SchemaException("Error reading array of size " + std::to_string(size) + ", only " + std::to_string(buffer->remaining()) + " bytes available");
	
	ObjectArray *objs = new ObjectArray(size);
	for (int i = 0; i < size; i++)
		(*objs)[i] = type_->read(buffer);
	return objs;
}

int ArrayOf::sizeOf(Object *o)
{
	int size = 4;
	if (o == NULL)
		return size;

	ObjectArray *objs = (ObjectArray*) o;
	for (int i = 0; i < *objs; i++)
		size += type_->sizeOf((*objs)[i]);
	return size;
}

Type* ArrayOf::type()
{
	return this->type_;
}

std::string ArrayOf::toString()
{
	std::string str = ARRAY_TYPE_NAME;
	return str + "(" + type_->toString() + ")";
}

Object* ArrayOf::validate(Object *item)
{
	if (isNullable() && item == NULL)
	{
		return NULL;
	}

	ObjectArray *array = (ObjectArray*)item;
	for (int i = 0; i < *array; i++)
		type_->validate((*array)[i]);
	return array;
}

std::string ArrayOf::typeName()
{
	return ARRAY_TYPE_NAME;
}

std::string ArrayOf::documentation()
{
	std::string str = "Represents a sequence of objects of a given type T. ";
	str += "Type T can be either a primitive type (e.g. ";
	str += Type::STRING()->toString();
	str += ") or a structure. ";
	str += "First, the length N is given as an ";
	str += Type::INT32()->toString();
	str += ". Then N instances of type T follow. ";
	str += "A null array is represented with a length of -1. "
		"In protocol documentation an array of T instances is referred to as [T].";
	return str;
}