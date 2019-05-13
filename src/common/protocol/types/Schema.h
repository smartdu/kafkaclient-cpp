#ifndef __KFK_SCHEMA_H__
#define __KFK_SCHEMA_H__

#pragma once
#include "Type.h"
#include <list>
#include <map>
class Field;
class BoundField;
class Struct;
class ArrayOf;
class Visitor;

class Schema
	: public Type
{
public:
	Schema(std::list<Field*> &fs);
	Schema(int num, ...);

	virtual void write(ByteBuffer *buffer, Object *o);

	virtual Object* read(ByteBuffer *buffer);

	virtual int sizeOf(Object *o);

	virtual int numFields();

	BoundField* get(int slot);

	BoundField* get(const char *name);

	BoundField** fields();

	virtual std::string toString();

	virtual Object* validate(Object *item);

	void walk(Visitor *visitor);

    Schema* clone()
    {
        ref_++;
        return this;
    }

    static void destroy(Schema *s)
    {
        if (s != NULL)
        {
            if (s->ref_ == 0)
                delete s;
            else
                s->ref_--;
        }
    }

private:
	static void handleNode(Type *node, Visitor *visitor);

    virtual ~Schema();

private:
	BoundField **fields_;
	int length;
	std::map<std::string, BoundField*> fieldsByName;
    int ref_;
};

class Visitor
{
public:
	virtual void visitor(Schema *schema);

	virtual void visitor(ArrayOf *array);

	virtual void visitor(Type *field);
};

#endif // !__KFK_SCHEMA_H__
