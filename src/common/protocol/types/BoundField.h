#ifndef __KFK_BOUNDFIELD_H__
#define __KFK_BOUNDFIELD_H__

#pragma once
class Field;
class Schema;
#include "Object.h"

class BoundField
	: public Object
{
public:
	Field *def;
	int index;
	Schema *schema;

	BoundField(Field *def, Schema *schema, int index);
    virtual ~BoundField();

	virtual std::string toString();
};

#endif // !__KFK_BOUNDFIELD_H__
