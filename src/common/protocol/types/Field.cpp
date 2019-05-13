#include "Field.h"
#include "Type.h"
#include "Object.h"
#include "ArrayOf.h"
#include "Schema.h"
#include "Byte.h"
#include "Integer.h"
#include "Long.h"
#include <stdarg.h>

Field::Field(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue)
{
	init(name, type, docString, hasDefaultValue, defaultValue);
}

Field::Field(const char *name, Type *type, const char *docString)
{
	init(name, type, docString, false, NULL);
}

Field::Field(const char *name, Type *type, const char *docString, Object *defaultValue)
{
	init(name, type, docString, true, defaultValue);
}

Field::Field(const char *name, Type *type)
{
	init(name, type, "", false, NULL);
}

Field::Field()
{
	init("", NULL, "", false, NULL);
}

Field::~Field()
{
    if (defaultValue != NULL)
        delete defaultValue;
    if (type != NULL)
        delete type;
}

void Field::init(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue)
{
	this->name = name;
	this->docString = docString;
	this->type = type;
	this->hasDefaultValue = hasDefaultValue;
	this->defaultValue = defaultValue;

	if (hasDefaultValue)
		type->validate(defaultValue);
}

Int8::Int8(const char *name, const char *docString)
	: Field(name, Type::INT8(), docString, false, NULL)
{

}

Int8::Int8(const char *name, const char *docString, char defaultValue)
{
	Byte *b = new Byte(defaultValue);
	init(name, Type::INT8(), docString, true, b);
}

Int32::Int32(const char *name, const char *docString)
	: Field(name, Type::INT32(), docString, false, NULL)
{

}

Int32::Int32(const char *name, const char *docString, int defaultValue)
{
	Integer *b = new Integer(defaultValue);
	init(name, Type::INT32(), docString, true, b);
}

Int64::Int64(const char *name, const char *docString)
	: Field(name, Type::INT64(), docString, false, NULL)
{

}

Int64::Int64(const char *name, const char *docString, long long defaultValue)
{
	Long *b = new Long(defaultValue);
	init(name, Type::INT32(), docString, true, b);
}

Int16::Int16(const char *name, const char *docString)
	: Field(name, Type::INT16(), docString, false, NULL)
{

}

Str::Str(const char *name, const char *docString)
	: Field(name, Type::STRING(), docString, false, NULL)
{

}

NullableStr::NullableStr(const char *name, const char *docString)
	: Field(name, Type::NULLABLE_STRING(), docString, false, NULL)
{

}

Bool::Bool(const char *name, const char *docString)
	: Field(name, Type::BOOLEAN(), docString, false, NULL)
{

}

Array::Array(const char *name, Type *elementType, const char *docString)
	: Field(name, new ArrayOf(elementType), docString, false, NULL)
{

}

ComplexArray::ComplexArray(const char *name, const char *docString)
{
	this->name = name;
	this->docString = docString;
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