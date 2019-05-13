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
    bool canDelete;

	Field(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue, bool canDelete = true);
	Field(const char *name, Type *type, const char *docString, bool canDelete = true);
	Field(const char *name, Type *type, const char *docString, Object *defaultValue, bool canDelete = true);
	Field(const char *name, Type *type);

    static void destroy(Field *f);

    static std::list<Field*> values();

protected:
	void init(const char *name, Type *type, const char *docString, bool hasDefaultValue, Object *defaultValue, bool canDelete);

    virtual ~Field();
};

class Int8
	: public Field
{
public:
	Int8(const char *name, const char *docString, bool canDelete = true);
	Int8(const char *name, const char *docString, char defaultValue, bool canDelete = true);
};

class Int32
	: public Field
{
public:
	Int32(const char *name, const char *docString, bool canDelete = true);
	Int32(const char *name, const char *docString, int defaultValue, bool canDelete = true);
};

class Int64
	: public Field
{
public:
	Int64(const char *name, const char *docString, bool canDelete = true);
	Int64(const char *name, const char *docString, long long defaultValue, bool canDelete = true);
};

class Int16
	: public Field
{
public:
	Int16(const char *name, const char *docString, bool canDelete = true);
};

class Str
	: public Field
{
public:
	Str(const char *name, const char *docString, bool canDelete = true);
};

class NullableStr
	: public Field
{
public:
	NullableStr(const char *name, const char *docString, bool canDelete = true);
};

class Bool
	: public Field
{
public:
	Bool(const char *name, const char *docString, bool canDelete = true);
};

class Array
	: public Field
{
public:
	Array(const char *name, Type *elementType, const char *docString, bool canDelete = true);
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

	Field* withFields(const char *docStringOverride, std::list<Field*> fields);

    static std::list<ComplexArray*> values();
};

#endif // !__KFK_FIELD_H__
