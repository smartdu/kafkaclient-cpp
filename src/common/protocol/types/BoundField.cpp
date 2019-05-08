#include "BoundField.h"
#include "Field.h"
#include "Schema.h"
#include "Type.h"

BoundField::BoundField(Field *def, Schema *schema, int index)
{
	this->def = def;
	this->schema = schema;
	this->index = index;
}

std::string BoundField::toString()
{
	return def->name + ":" + def->type->toString();
}