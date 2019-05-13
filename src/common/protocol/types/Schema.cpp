#include "Schema.h"
#include "Field.h"
#include "BoundField.h"
#include "SchemaException.h"
#include "ArrayOf.h"
#include "Struct.h"
#include "ObjectArray.h"
#include <stdarg.h>

Schema::Schema(std::list<Field*> &fs)
{
    if (fs.size() > 0)
        this->fields_ = new BoundField*[fs.size()];
    else
        this->fields_ = NULL;
	this->length = fs.size();
	int i = 0;
	for (auto iter : fs)
	{
		Field *def = iter;
		if (fieldsByName.find(def->name) != fieldsByName.end())
		{
			throw SchemaException("Schema contains a duplicate field: " + def->name);
		}
		this->fields_[i] = new BoundField(def, this, i);
		this->fieldsByName[def->name] = this->fields_[i];
		i++;
	}
}

Schema::Schema(int num, ...)
{
	va_list valist;
	va_start(valist, num);
	std::list<Field*> fl;
	for (int i = 0; i < num; i++)
	{
		Field *def = va_arg(valist, Field*);
		fl.push_back(def);
	}
	va_end(valist);
	new (this)Schema(fl);
}

Schema::~Schema()
{
    for (int i = 0; i < length; i++)
        delete this->fields_[i];

    if (this->fields_ != NULL)
        delete[] this->fields_;
}

void Schema::write(ByteBuffer *buffer, Object *o)
{

}

Object* Schema::read(ByteBuffer *buffer)
{
	ObjectArray *objects = new ObjectArray(length);
	for (int i = 0; i < length; i++)
	{
		(*objects)[i] = fields_[i]->def->type->read(buffer);
	}
	return new Struct(this, objects);
}

int Schema::sizeOf(Object *o)
{
	return 0;
}

int Schema::numFields()
{
	return this->length;
}

BoundField* Schema::get(int slot)
{
	return this->fields_[slot];
}

BoundField* Schema::get(const char *name)
{
	return this->fieldsByName[name];
}

BoundField** Schema::fields()
{
	return this->fields_;
}

std::string Schema::toString()
{
	std::string b;
	b.append("{");
	for (int i = 0; i < this->length; i++)
	{
		b.append(this->fields_[i]->toString());
		if (i < this->length - 1)
			b.append(",");
	}
	b.append("}");
	return b;
}

Object* Schema::validate(Object *item)
{
	return NULL;
}

void Schema::walk(Visitor *visitor)
{
	handleNode(this, visitor);
}

void Schema::handleNode(Type *node, Visitor *visitor)
{
	Schema *s = dynamic_cast<Schema*>(node);
	if (s != NULL)
	{
		visitor->visitor(s);
		for (int i = 0; i < s->length; i++)
		{
			handleNode(s->fields_[i]->def->type, visitor);
		}
		return;
	}
	ArrayOf *a = dynamic_cast<ArrayOf*>(node);
	if (a != NULL)
	{
		visitor->visitor(a);
		handleNode(a->type(), visitor);
		return;
	}
	visitor->visitor(node);
}

void Visitor::visitor(Schema *schema)
{

}

void Visitor::visitor(ArrayOf *array)
{

}

void Visitor::visitor(Type *field)
{
	
}