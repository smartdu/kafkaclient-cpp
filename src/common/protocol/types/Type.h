#ifndef __KFK_TYPE_H__
#define __KFK_TYPE_H__

#pragma once
#include <string>
#include <memory>
#include <list>
#include "Object.h"
#include "Type.h"
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
    friend class UNINIT;
    Type();

	virtual void write(ByteBuffer *buffer, Object *o) = 0;

	virtual Object* read(ByteBuffer *buffer) = 0;

	virtual Object* validate(Object* item) = 0;

	virtual int sizeOf(Object *o) = 0;

	virtual bool isNullable();

    static std::list<Type*> values();

    static void destroy(Type *t);

    Type* clone()
    {
        ref_++;
        clone_ = true;
        return this;
    }

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

    int ref_;
    bool clone_;
};

class DocumentedType
	: public Type
{
public:
    DocumentedType()
    {

    }
	virtual std::string typeName() = 0;

	virtual std::string documentation() = 0;

	virtual std::string toString();
};

class DocumentType_BOOLEAN
	: public DocumentedType
{
public:
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
	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual std::string typeName();

	virtual Object* validate(Object *item);

	virtual std::string documentation();
};

#endif // !__KFK_TYPE_H__
