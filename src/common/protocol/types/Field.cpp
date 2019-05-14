#include "Field.h"
#include "Type.h"
#include "Object.h"
#include "ArrayOf.h"
#include "Schema.h"
#include "Byte.h"
#include "Integer.h"
#include "Long.h"
#include <stdarg.h>

extern std::list<Field*> *_cf_values_;

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

Field::~Field()
{
    /*static FILE *file = fopen("D:\\field0.txt", "wb");
    static int count = 1;
    fprintf(file, "Field %p, %d, name = %s\n", this, count++, name.c_str());
    fflush(file);*/

    if (defaultValue != NULL)
        delete defaultValue;
    Type::destroy(type);
}

void Field::destroy(Field *f)
{
    if (f != NULL)
    {
        if (f->ref_ == 0)
        {
            delete f;
        }
        else
        {
            f->ref_--;
        }
    }
}

std::list<Field*> Field::values()
{
    std::list<Field*> l = *_cf_values_;
    delete _cf_values_;
    _cf_values_ = NULL;
    return l;
}

void Field::init(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue)
{
    ref_ = 1;
	this->name = name;
	this->docString = docString;
	this->type = type;
	this->hasDefaultValue = hasDefaultValue;
	this->defaultValue = defaultValue;
    _cf_values_->push_back(this);

	if (hasDefaultValue)
		type->validate(defaultValue);

    /*static FILE *file = fopen("D:\\field.txt", "wb");
    static int count = 1;
    fprintf(file, "Field %p, %d, name = %s\n", this, count++, name);
    fflush(file);*/
}

Int8::Int8(const char *name, const char *docString)
	: Field(name, Type::INT8()->clone(), docString, false, NULL)
{

}

Int8::Int8(const char *name, const char *docString, char defaultValue)
    : Field(name, Type::INT8()->clone(), docString, true, new Byte(defaultValue))
{

}

Int32::Int32(const char *name, const char *docString)
	: Field(name, Type::INT32()->clone(), docString, false, NULL)
{

}

Int32::Int32(const char *name, const char *docString, int defaultValue)
    : Field(name, Type::INT32()->clone(), docString, true, new Integer(defaultValue))
{

}

Int64::Int64(const char *name, const char *docString)
	: Field(name, Type::INT64()->clone(), docString, false, NULL)
{

}

Int64::Int64(const char *name, const char *docString, long long defaultValue)
    : Field(name, Type::INT32()->clone(), docString, true, new Long(defaultValue))
{

}

Int16::Int16(const char *name, const char *docString)
	: Field(name, Type::INT16()->clone(), docString, false, NULL)
{

}

Str::Str(const char *name, const char *docString)
	: Field(name, Type::STRING()->clone(), docString, false, NULL)
{

}

NullableStr::NullableStr(const char *name, const char *docString)
	: Field(name, Type::NULLABLE_STRING()->clone(), docString, false, NULL)
{

}

Bool::Bool(const char *name, const char *docString)
	: Field(name, Type::BOOLEAN()->clone(), docString, false, NULL)
{

}

Array::Array(const char *name, Type *elementType, const char *docString)
	: Field(name, new ArrayOf(elementType), docString, false, NULL)
{

}

static std::list<ComplexArray*> *_ca_values_ = new std::list<ComplexArray*>();

ComplexArray::ComplexArray(const char *name, const char *docString)
{
	this->name = name;
	this->docString = docString;

    _ca_values_->push_back(this);

    /*static FILE *file = fopen("D:\\complex.txt", "wb");
    static int count = 1;
    fprintf(file, "ComplexArray %p, count = %d\n", this, count++);
    fflush(file);*/
}

ComplexArray::~ComplexArray()
{
    /*static FILE *file = fopen("D:\\complex0.txt", "wb");
    static int count = 1;
    fprintf(file, "~ComplexArray %p, count = %d\n", this, count++);
    fflush(file);*/
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

Field* ComplexArray::withFields(const char *docStringOverride, int num, ...)
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
	return new Field(name.c_str(), new ArrayOf(elementType), docStringOverride, false, NULL);
}

std::list<ComplexArray*> ComplexArray::values()
{
    std::list<ComplexArray*> l = *_ca_values_;
    delete _ca_values_;
    _ca_values_ = NULL;
    return l;
}
