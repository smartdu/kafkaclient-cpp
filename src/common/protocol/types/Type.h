#ifndef __KFK_TYPE_H__
#define __KFK_TYPE_H__

#pragma once
#include <string>
#include <memory>
#include "Object.h"
class ByteBuffer;
class Object;
class DocumentedType;
class Byte;
class Short;
class Integer;
class Long;
class String;
class BaseRecords;

class Type
	: public Object
{
public:
    Type(bool canDelete = true)
    {
        this->canDelete = canDelete;
    }

	virtual void write(ByteBuffer *buffer, Object *o) = 0;

	virtual Object* read(ByteBuffer *buffer) = 0;

	virtual Object* validate(Object* item) = 0;

	virtual int sizeOf(Object *o) = 0;

	virtual bool isNullable();

    static void destroy(Type *t);

public:
	static DocumentedType* BOOLEAN();

	static DocumentedType* INT8();

	static DocumentedType* INT16();

	static DocumentedType* INT32();

	static DocumentedType* INT64();

	static DocumentedType* NULLABLE_BYTES();

	static DocumentedType* STRING();

	static DocumentedType* NULLABLE_STRING();

protected:
    virtual ~Type()
    {

    }

    bool canDelete;
};

class DocumentedType
	: public Type
{
public:
	virtual std::string typeName() = 0;

	virtual std::string documentation() = 0;

	virtual std::string toString();
};

class DocumentType_BOOLEAN
	: public DocumentedType
{
public:
    DocumentType_BOOLEAN()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_INT8
	: public DocumentedType
{
public:
    DocumentedType_INT8()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_INT16
	: public DocumentedType
{
public:
    DocumentedType_INT16()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_INT32
	: public DocumentedType
{
public:
    DocumentedType_INT32()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_UNSIGNED_INT32
	: public DocumentedType
{
public:
    DocumentedType_UNSIGNED_INT32()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_INT64
	: public DocumentedType
{
public:
    DocumentedType_INT64()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_STRING
	: public DocumentedType
{
public:
    DocumentedType_STRING()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_NULLABLE_STRING
	: public DocumentedType
{
public:
    DocumentedType_NULLABLE_STRING()
    {
        canDelete = false;
    }

	virtual bool isNullable()
	{
		return true;
	}

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_BYTES
	: public DocumentedType
{
public:
    DocumentedType_BYTES()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_NULLABLE_BYTES
	: public DocumentedType
{
public:
    DocumentedType_NULLABLE_BYTES()
    {
        canDelete = false;
    }

	virtual bool isNullable()
	{
		return true;
	}

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_RECORDS
	: public DocumentedType
{
public:
    DocumentedType_RECORDS()
    {
        canDelete = false;
    }

	virtual bool isNullable()
	{
		return true;
	}

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_VARINT
	: public DocumentedType
{
public:
    DocumentedType_VARINT()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

class DocumentedType_VARLONG
	: public DocumentedType
{
public:
    DocumentedType_VARLONG()
    {
        canDelete = false;
    }

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

#endif // !__KFK_TYPE_H__
