#ifndef __KFK_FIELD_H__
#define __KFK_FIELD_H__

#pragma once
class Type;
class Object;
#include <list>
#include <string>

class Field
{
public:
    friend class UNINIT;
	std::string name;
	std::string docString;
	Type *type;
	bool hasDefaultValue;
	Object *defaultValue;

	Field(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue);
	Field(const char *name, Type *type, const char *docString);
	Field(const char *name, Type *type, const char *docString, Object *defaultValue);
	Field(const char *name, Type *type);

    static void destroy(Field *f);

    static std::list<Field*> values();

    Field* clone()
    {
        ref_++;
        return this;
    }

protected:
	void init(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue);

    virtual ~Field();

private:
    int ref_;
};

class Int8
	: public Field
{
public:
	Int8(const char *name, const char *docString);
	Int8(const char *name, const char *docString, char defaultValue);
};

class Int32
	: public Field
{
public:
	Int32(const char *name, const char *docString);
	Int32(const char *name, const char *docString, int defaultValue);
};

class Int64
	: public Field
{
public:
	Int64(const char *name, const char *docString);
	Int64(const char *name, const char *docString, long long defaultValue);
};

class Int16
	: public Field
{
public:
	Int16(const char *name, const char *docString);
};

class Str
	: public Field
{
public:
	Str(const char *name, const char *docString);
};

class NullableStr
	: public Field
{
public:
	NullableStr(const char *name, const char *docString);
};

class Bool
	: public Field
{
public:
	Bool(const char *name, const char *docString);
};

class Array
	: public Field
{
public:
	Array(const char *name, Type *elementType, const char *docString);
};

class ComplexArray
{
public:
	std::string name;
	std::string docString;

	ComplexArray(const char *name, const char *docString);
    virtual ~ComplexArray();

	Field* withFields(int num, ...);

	Field* nullableWithFields(int num, ...);

	Field* withFields(const char *docStringOverride, int num, ...);

    static std::list<ComplexArray*> values();
};

#endif // !__KFK_FIELD_H__
