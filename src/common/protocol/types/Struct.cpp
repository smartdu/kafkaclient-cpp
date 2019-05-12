#include "Struct.h"
#include "Schema.h"
#include "ObjectArray.h"
#include "SchemaException.h"
#include "Field.h"
#include "BoundField.h"
#include "ByteBuffer.h"
#include "ByteArray.h"
#include "Byte.h"
#include "Integer.h"
#include "Long.h"
#include "Short.h"
#include "String0.h"
#include "ArrayOf.h"
#include "Boolean.h"
#include "Arrays.h"

Struct::Struct(Schema *schema, ObjectArray *values)
{
	this->schema_ = schema;
	this->values = values;
}

Struct::Struct(Schema *schema)
{
	this->schema_ = schema;
	this->values = new ObjectArray(this->schema_->numFields());
}

Schema* Struct::schema()
{
	return this->schema_;
}

Object* Struct::getFieldOrDefault(BoundField *field)
{
	Object *value = (*this->values)[field->index];
	if (value != NULL)
		return value;
	else if (field->def->hasDefaultValue)
		return field->def->defaultValue;
	else if (field->def->type->isNullable())
		return NULL;
	else
		throw SchemaException("Missing value for field '" + field->def->name + "' which has no default value.");
}

Object* Struct::get(BoundField *field)
{
	validateField(field);
	return getFieldOrDefault(field);
}

Byte* Struct::get(Int8 *field)
{
	Byte *b = new Byte(getByte(field->name.c_str()));
	return b;
}

Integer* Struct::get(Int32 *field)
{
	return getInt(field->name.c_str());
}

Long* Struct::get(Int64 *field)
{
	return getLong(field->name.c_str());
}

Short* Struct::get(Int16 *field)
{
	return getShort(field->name.c_str());
}

String* Struct::get(Str *field)
{
	return getString(field->name.c_str());
}

String* Struct::get(NullableStr *field)
{
	return getString(field->name.c_str());
}

Boolean* Struct::get(Bool *field)
{
	return getBoolean(field->name.c_str());
}

ObjectArray* Struct::get(Array *field)
{
	return getArray(field->name.c_str());
}

ObjectArray* Struct::get(ComplexArray *field)
{
	return getArray(field->name.c_str());
}

Long* Struct::getOrElse(Int64 *field, long long alternative)
{
	if (hasField(field->name.c_str()))
		return getLong(field->name.c_str());
	return new Long(alternative);
}

Short* Struct::getOrElse(Int16 *field, short alternative)
{
	if (hasField(field->name.c_str()))
		return getShort(field->name.c_str());
	return new Short(alternative);
}

Byte* Struct::getOrElse(Int8 *field, char alternative)
{
	if (hasField(field->name.c_str()))
		return new Byte(getByte(field->name.c_str()));
	return new Byte(alternative);
}

Integer* Struct::getOrElse(Int32 *field, int alternative)
{
	if (hasField(field->name.c_str()))
		return getInt(field->name.c_str());
	return new Integer(alternative);
}

String* Struct::getOrElse(NullableStr *field, const char *alternative)
{
	if (hasField(field->name.c_str()))
		return getString(field->name.c_str());
	return new String(alternative);
}

String* Struct::getOrElse(Str *field, const char *alternative)
{
	if (hasField(field->name.c_str()))
		return getString(field->name.c_str());
	return new String(alternative);
}

bool Struct::getOrElse(Bool *field, bool alternative)
{
	if (hasField(field->name.c_str()))
		return *getBoolean(field->name.c_str());
	return alternative;
}

ObjectArray* Struct::getOrEmpty(Array *field)
{
	if (hasField(field->name.c_str()))
		return getArray(field->name.c_str());
	return new ObjectArray(0);
}

ObjectArray* Struct::getOrEmpty(ComplexArray *field)
{
	if (hasField(field->name.c_str()))
		return getArray(field->name.c_str());
	return new ObjectArray(0);
}

Object* Struct::get(const char *name)
{
	BoundField *field = schema_->get(name);
	if (field == NULL)
		throw SchemaException("No such field: " + std::string(name));
	return getFieldOrDefault(field);
}

bool Struct::hasField(const char *name)
{
	return schema_->get(name) != NULL;
}

bool Struct::hasField(Field *def)
{
	return schema_->get(def->name.c_str()) != NULL;
}

bool Struct::hasField(ComplexArray *def)
{
	return schema_->get(def->name.c_str()) != NULL;
}

Struct* Struct::getStruct(BoundField *field)
{
	return (Struct*)get(field);
}

Struct* Struct::getStruct(const char *name)
{
	return (Struct*)get(name);
}

Byte* Struct::getByte(BoundField *field)
{
	return (Byte*)get(field);
}

char Struct::getByte(const char *name)
{
	return *(Byte*)get(name);
}

BaseRecords* Struct::getRecords(const char *name)
{
	return (BaseRecords*)get(name);
}

Short* Struct::getShort(BoundField *field)
{
	return (Short*)get(field);
}

Short* Struct::getShort(const char *name)
{
	return (Short*)get(name);
}

Integer* Struct::getInt(BoundField *field)
{
	return (Integer*)get(field);
}

Integer* Struct::getInt(const char *name)
{
	return (Integer*)get(name);
}

Long* Struct::getUnsignedInt(const char *name)
{
	return (Long*)get(name);
}

Long* Struct::getLong(BoundField *field)
{
	return (Long*)get(field);
}

Long* Struct::getLong(const char *name)
{
	return (Long*)get(name);
}

ObjectArray* Struct::getArray(BoundField *field)
{
	return (ObjectArray*) get(field);
}

ObjectArray* Struct::getArray(const char *name)
{
	return (ObjectArray*) get(name);
}

String* Struct::getString(BoundField *field)
{
	return (String*)get(field);
}

String* Struct::getString(const char *name)
{
	return (String*)get(name);
}

Boolean* Struct::getBoolean(BoundField *field)
{
	return (Boolean*)get(field);
}

Boolean* Struct::getBoolean(const char *name)
{
	return (Boolean*)get(name);
}

ByteBuffer* Struct::getBytes(BoundField *field)
{
	Object *result = get(field);
	ByteArray *a = dynamic_cast<ByteArray*>(result);
	if (a != NULL)
		return ByteBuffer::wrap(a);
	return (ByteBuffer*)result;
}

ByteBuffer* Struct::getBytes(const char *name)
{
	Object *result = get(name);
	ByteArray *a = dynamic_cast<ByteArray*>(result);
	if (a != NULL)
		return ByteBuffer::wrap(a);
	return (ByteBuffer*)result;
}

ByteArray* Struct::getByteArray(const char *name)
{
	Object *result = get(name);
	ByteArray *a = dynamic_cast<ByteArray*>(result);
	if (a != NULL)
		return a;
	ByteBuffer *buf = (ByteBuffer*)result;
	ByteArray *arr = new ByteArray(buf->remaining());
	buf->get(arr);
	return arr;
}

Struct* Struct::set(BoundField *field, Object *value)
{
	validateField(field);
	(*this->values)[field->index] = value;
	return this;
}

Struct* Struct::set(const char *name, Object *value)
{
	BoundField *field = this->schema_->get(name);
	if (field == NULL)
		throw SchemaException("Unknown field: " + std::string(name));
	(*this->values)[field->index] = value;
	return this;
}

Struct* Struct::set(Str *def, const char *value)
{
	return set(def->name.c_str(), new String(value));
}

Struct* Struct::set(NullableStr *def, const char *value)
{
	return set(def->name.c_str(), new String(value));
}

Struct* Struct::set(Int8 *def, char value)
{
	return set(def->name.c_str(), new Byte(value));
}

Struct* Struct::set(Int32 *def, int value)
{
	return set(def->name.c_str(), new Integer(value));
}

Struct* Struct::set(Int64 *def, long long value)
{
	return set(def->name.c_str(), new Long(value));
}

Struct* Struct::set(Int16 *def, short value)
{
	return set(def->name.c_str(), new Short(value));
}

Struct* Struct::set(Bool *def, bool value)
{
	return set(def->name.c_str(), new Boolean(value));
}

Struct* Struct::set(Array *def, ObjectArray *value)
{
	return set(def->name.c_str(), value);
}

Struct* Struct::set(ComplexArray *def, ObjectArray *value)
{
	return set(def->name.c_str(), value);
}

Struct* Struct::setByteArray(const char *name, ByteArray *value)
{
	ByteBuffer *buf = value == NULL ? NULL : ByteBuffer::wrap(value);
	return set(name, buf);
}

Struct* Struct::setIfExists(Array *def, ObjectArray *value)
{
	return setIfExists(def->name.c_str(), value);
}

Struct* Struct::setIfExists(ComplexArray *def, ObjectArray *value)
{
	return setIfExists(def->name.c_str(), value);
}

Struct* Struct::setIfExists(Field *def, Object *value)
{
	return setIfExists(def->name.c_str(), value);
}

Struct* Struct::setIfExists(const char *fieldName, Object *value)
{
	BoundField *field = this->schema_->get(fieldName);
	if (field != NULL)
		(*this->values)[field->index] = value;
	return this;
}

Struct* Struct::instance(BoundField *field)
{
	validateField(field);
	Schema *s = dynamic_cast<Schema*>(field->def->type);
	if (s != NULL)
	{
		return new Struct(s);
	}
	
	ArrayOf *a = dynamic_cast<ArrayOf*>(field->def->type);
	if (a != NULL)
	{
		return new Struct((Schema*)a->type());
	}

	throw SchemaException("Field '" + field->def->name + "' is not a container type, it is of type " + field->def->type->toString());
}

Struct* Struct::instance(const char *field)
{
	return instance(schema_->get(field));
}

Struct* Struct::instance(Field *field)
{
	return instance(schema_->get(field->name.c_str()));
}

Struct* Struct::instance(ComplexArray *field)
{
	return instance(schema_->get(field->name.c_str()));
}

void Struct::clear()
{
	Arrays::fill(this->values, NULL);
}

int Struct::sizeOf()
{
	return this->schema_->sizeOf(this);
}

void Struct::writeTo(ByteBuffer *buffer)
{
	this->schema_->write(buffer, this);
}

void Struct::validateField(BoundField *field)
{
	if (this->schema_ != field->schema)
		throw SchemaException("Attempt to access field '" + field->def->name + "' from a different schema instance.");

	int length = 0;
	for (length = 0; (*values)[length] != NULL; length++);
	if (field->index > length)
		throw SchemaException("Invalid field index: " + field->index);
}

void Struct::validate()
{
	this->schema_->validate(this);
}