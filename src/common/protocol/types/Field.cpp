#include "Field.h"
#include "Type.h"
#include "Object.h"
#include "ArrayOf.h"
#include "Schema.h"
#include "Byte.h"
#include "Integer.h"
#include "Long.h"
#include <stdarg.h>

Field::Field(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue, bool canDelete/* = true*/)
{
	init(name, type, docString, hasDefaultValue, defaultValue, canDelete);
}

Field::Field(const char *name, Type *type, const char *docString, bool canDelete/* = true*/)
{
	init(name, type, docString, false, NULL, canDelete);
}

Field::Field(const char *name, Type *type, const char *docString, Object *defaultValue, bool canDelete/* = true*/)
{
	init(name, type, docString, true, defaultValue, canDelete);
}

Field::Field(const char *name, Type *type)
{
	init(name, type, "", false, NULL, canDelete);
}

Field::~Field()
{
    if (defaultValue != NULL)
        delete defaultValue;
    Type::destroy(type);
}

void Field::destroy(Field *f)
{
    if (f != NULL && f->canDelete)
        delete f;
}

void Field::init(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue, bool canDelete)
{
	this->name = name;
	this->docString = docString;
	this->type = type;
	this->hasDefaultValue = hasDefaultValue;
	this->defaultValue = defaultValue;
    this->canDelete = canDelete;

	if (hasDefaultValue)
		type->validate(defaultValue);
}

Int8::Int8(const char *name, const char *docString)
	: Field(name, Type::INT8(), docString, false, NULL, false)
{

}

Int8::Int8(const char *name, const char *docString, char defaultValue)
    : Field(name, Type::INT8(), docString, true, new Byte(defaultValue), false)
{

}

Int32::Int32(const char *name, const char *docString)
	: Field(name, Type::INT32(), docString, false, NULL, false)
{

}

Int32::Int32(const char *name, const char *docString, int defaultValue)
    : Field(name, Type::INT32(), docString, true, new Integer(defaultValue), false)
{

}

Int64::Int64(const char *name, const char *docString)
	: Field(name, Type::INT64(), docString, false, NULL, false)
{

}

Int64::Int64(const char *name, const char *docString, long long defaultValue)
    : Field(name, Type::INT32(), docString, true, new Long(defaultValue), false)
{

}

Int16::Int16(const char *name, const char *docString)
	: Field(name, Type::INT16(), docString, false, NULL, false)
{

}

Str::Str(const char *name, const char *docString)
	: Field(name, Type::STRING(), docString, false, NULL, false)
{

}

NullableStr::NullableStr(const char *name, const char *docString)
	: Field(name, Type::NULLABLE_STRING(), docString, false, NULL, false)
{

}

Bool::Bool(const char *name, const char *docString)
	: Field(name, Type::BOOLEAN(), docString, false, NULL, false)
{

}

Array::Array(const char *name, Type *elementType, const char *docString)
	: Field(name, new ArrayOf(elementType), docString, false, NULL, false)
{

}

ComplexArray::ComplexArray(const char *name, const char *docString)
{
	this->name = name;
	this->docString = docString;
}

ComplexArray::~ComplexArray()
{

}

Field* ComplexArray::withFields(int num, ...)
{
	std::list<Field*> fl;
	va_list valist;
	va_start(valist, num);
	for (int i = 0; i < num; i++)
	{
		Field *def = va_arg(valist, Field*);
		fl.push_back(def);
	}
	va_end(valist);
	Schema *elementType = new Schema(fl);
	return new Field(name.c_str(), new ArrayOf(elementType), docString.c_str(), false, NULL);
}

Field* ComplexArray::nullableWithFields(int num, ...)
{
	std::list<Field*> fl;
	va_list valist;
	va_start(valist, num);
	for (int i = 0; i < num; i++)
	{
		Field *def = va_arg(valist, Field*);
		fl.push_back(def);
	}
	va_end(valist);
	Schema *elementType = new Schema(fl);
	return new Field(name.c_str(), ArrayOf::nullable(elementType), docString.c_str(), false, NULL);
}

Field* ComplexArray::withFields(const char *docStringOverride, std::list<Field*> fields)
{
	Schema *elementType = new Schema(fields);
	return new Field(name.c_str(), new ArrayOf(elementType), docStringOverride, false, NULL);
}