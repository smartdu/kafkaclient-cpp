#ifndef __KFK_STRUCT_H__
#define __KFK_STRUCT_H__

#pragma once
#include "Object.h"
class Schema;
class ObjectArray;
class BoundField;
class Object;
class Byte;
class Int8;
class Integer;
class Int32;
class Long;
class Int64;
class Short;
class Int16;
class String;
class Str;
class NullableStr;
class Boolean;
class Bool;
class Array;
class ComplexArray;
class Field;
class ByteArray;
class BaseRecords;
class ByteBuffer;

class Struct
	: public Object
{
public:
	Struct(Schema *schema, ObjectArray *values);
	Struct(Schema *schema);
    virtual ~Struct();

	Schema* schema();

	Object* get(BoundField *filed);

	Byte* get(Int8 *field);

	Integer* get(Int32 *field);

	Long* get(Int64 *field);

	Short* get(Int16 *field);

	String* get(Str *field);

	String* get(NullableStr *field);

	Boolean* get(Bool *field);

	ObjectArray* get(Array *field);

	ObjectArray* get(ComplexArray *field);

	Long* getOrElse(Int64 *field, long long alternative);

	Short* getOrElse(Int16 *field, short alternative);

	Byte* getOrElse(Int8 *field, char alternative);

	Integer* getOrElse(Int32 *field, int alternative);

	String* getOrElse(NullableStr *field, const char *alternative);

	String* getOrElse(Str *field, const char * alternative);

	bool getOrElse(Bool *field, bool alternative);

	ObjectArray* getOrEmpty(Array *field);

	ObjectArray* getOrEmpty(ComplexArray *field);

	Object* get(const char *name);

	bool hasField(const char *name);

	bool hasField(Field *def);

	bool hasField(ComplexArray *def);

	Struct* getStruct(BoundField *field);

	Struct* getStruct(const char *name);

	Byte* getByte(BoundField *field);

	char getByte(const char *name);

	BaseRecords* getRecords(const char *name);

	Short* getShort(BoundField *field);

	Short* getShort(const char *name);

	Integer* getInt(BoundField *field);

	Integer* getInt(const char *name);

	Long* getUnsignedInt(const char *name);

	Long* getLong(BoundField *field);

	Long* getLong(const char *name);

	ObjectArray* getArray(BoundField *field);

	ObjectArray* getArray(const char *name);

	String* getString(BoundField *field);

	String* getString(const char *name);

	Boolean* getBoolean(BoundField *field);

	Boolean* getBoolean(const char *name);

	ByteBuffer* getBytes(BoundField *field);

	ByteBuffer* getBytes(const char *name);

	ByteArray* getByteArray(const char *name);
	
	Struct* set(BoundField *field, Object *value);

	Struct* set(const char *name, Object *value);
	
	Struct* set(Str *def, const char *value);
	
	Struct* set(NullableStr *def, const char *value);
	
	Struct* set(Int8 *def, char value);
	
	Struct* set(Int32 *def, int value);
	
	Struct* set(Int64 *def, long long value);
	
	Struct* set(Int16 *def, short value);
	
	Struct* set(Bool *def, bool value);
	
	Struct* set(Array *def, ObjectArray *value);
	
	Struct* set(ComplexArray *def, ObjectArray *value);
	
	Struct* setByteArray(const char *name, ByteArray *value);

	Struct* setIfExists(Array *def, ObjectArray *value);

	Struct* setIfExists(ComplexArray *def, ObjectArray *value);
	
	Struct* setIfExists(Field *def, Object *value);

	Struct* setIfExists(const char *fieldName, Object *value);

	Struct* instance(BoundField *field);

	Struct* instance(const char *field);
	
	Struct* instance(Field *field);
	
	Struct* instance(ComplexArray *field);

	void clear();

	int sizeOf();

	void writeTo(ByteBuffer *buffer);

	void validate();

private:
	Object* getFieldOrDefault(BoundField *field);

	void validateField(BoundField *field);

private:
	Schema *schema_;
	ObjectArray *values;
};

#endif // !__KFK_STRUCT_H__
