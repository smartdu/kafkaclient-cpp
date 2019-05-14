#include "Type.h"
#include "ByteBuffer.h"
#include "Object.h"
#include "SchemaException.h"
#include "Byte.h"
#include "Boolean.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "BaseRecords.h"
#include "ByteUtils.h"
#include "Utils.h"
#include "ByteArray.h"
#include "String0.h"

extern std::list<Type*> *_t_values_;

Type::Type()
    : ref_(1)
    , clone_(false)
{
    _t_values_->push_back(this);

    /*static FILE *file = fopen("D:\\type.txt", "wb");
    static int count = 1;
    fprintf(file, "Type %p, %d\n", this, count++);
    fflush(file);*/
}

bool Type::isNullable()
{
	return false;
}

std::list<Type*> Type::values()
{
    std::list<Type*> l = *_t_values_;
    delete _t_values_;
    _t_values_ = NULL;
    return l;
}

void Type::destroy(Type *t)
{
    if (t != NULL)
    {
        if (t->ref_ == 0 || !t->clone_)
        {
            delete t;
        }
        else
        {
            t->ref_--;
        }
    }
}

void Type::destroy()
{
    Type::destroy(Type::BOOLEAN());
    Type::destroy(Type::INT8());
    Type::destroy(Type::INT16());
    Type::destroy(Type::INT32());
    Type::destroy(Type::INT64());
    Type::destroy(Type::NULLABLE_BYTES());
    Type::destroy(Type::STRING());
    Type::destroy(Type::NULLABLE_STRING());
}

DocumentedType* Type::BOOLEAN()
{
	static DocumentedType *once = new DocumentType_BOOLEAN;
    return once;
}

DocumentedType* Type::INT8()
{
	static DocumentedType *once = new DocumentedType_INT8;
    return once;
}

DocumentedType* Type::INT16()
{
	static DocumentedType *once = new DocumentedType_INT16;
    return once;
}

DocumentedType* Type::INT32()
{
	static DocumentedType *once = new DocumentedType_INT32;
    return once;
}

DocumentedType* Type::INT64()
{
	static DocumentedType *once = new DocumentedType_INT64;
    return once;
}

DocumentedType* Type::NULLABLE_BYTES()
{
	static DocumentedType *once = new DocumentedType_NULLABLE_BYTES;
    return once;
}

DocumentedType* Type::STRING()
{
	static DocumentedType *once = new DocumentedType_STRING;
    return once;
}

DocumentedType* Type::NULLABLE_STRING()
{
	static DocumentedType *once = new DocumentedType_NULLABLE_STRING;
    return once;
}

std::string DocumentedType::toString()
{
	return typeName();
}

//----------------------------------------------------------------------

void DocumentType_BOOLEAN::write(ByteBuffer *buffer, Object *o)
{
	Boolean *b = dynamic_cast<Boolean*>(o);
	if (b != NULL)
	{
		if ((bool)*b)
			buffer->put((char)1);
		else
			buffer->put((char)0);
	}
}

Object* DocumentType_BOOLEAN::read(ByteBuffer *buffer)
{
	char value = buffer->get();
	Boolean *b = new Boolean(value != 0);
	return b;
}

int DocumentType_BOOLEAN::sizeOf(Object *o)
{
	return 1;
}

std::string DocumentType_BOOLEAN::typeName()
{
	return "BOOLEAN";
}

Object* DocumentType_BOOLEAN::validate(Object *item)
{
	Boolean *b = dynamic_cast<Boolean*>(item);
	if (b != NULL)
	{
		return b;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a Boolean.");
	}
}

std::string DocumentType_BOOLEAN::documentation()
{
	return "Represents a boolean value in a byte. "
		"Values 0 and 1 are used to represent false and true respectively. "
		"When reading a boolean value, any non-zero value is considered true.";
}

//----------------------------------------------------------------------

void DocumentedType_INT8::write(ByteBuffer *buffer, Object *o)
{
	buffer->put(*(Byte*)o);
}

Object* DocumentedType_INT8::read(ByteBuffer *buffer)
{
	Byte *b = new Byte(buffer->get());
	return b;
}

int DocumentedType_INT8::sizeOf(Object *o)
{
	return 1;
}

std::string DocumentedType_INT8::typeName()
{
	return "INT8";
}

Object* DocumentedType_INT8::validate(Object *item)
{
	Byte *b = dynamic_cast<Byte*>(item);
	if (b != NULL)
	{
		return b;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a Byte.");
	}
}

std::string DocumentedType_INT8::documentation()
{
	return "Represents an integer between -2<sup>7</sup> and 2<sup>7</sup>-1 inclusive.";
}

//----------------------------------------------------------------------

void DocumentedType_INT16::write(ByteBuffer *buffer, Object *o)
{
	Short *s = dynamic_cast<Short*>(o);
	buffer->putShort(*s);
}

Object* DocumentedType_INT16::read(ByteBuffer *buffer)
{
	Short *s = new Short(buffer->getShort());
	return s;
}

int DocumentedType_INT16::sizeOf(Object *o)
{
	return 2;
}

std::string DocumentedType_INT16::typeName()
{
	return "INT16";
}

Object* DocumentedType_INT16::validate(Object *item)
{
	Short *s = dynamic_cast<Short*>(item);
	if (s != NULL)
	{
		return s;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a Short.");
	}
}

std::string DocumentedType_INT16::documentation()
{
	return "Represents an integer between -2<sup>15</sup> and 2<sup>15</sup>-1 inclusive. "
		"The values are encoded using two bytes in network byte order (big-endian).";
}

//----------------------------------------------------------------------

void DocumentedType_INT32::write(ByteBuffer *buffer, Object *o)
{
	buffer->putInt(*(Integer*)o);
}

Object* DocumentedType_INT32::read(ByteBuffer *buffer)
{
	Integer *i = new Integer(buffer->getInt());
	return i;
}

int DocumentedType_INT32::sizeOf(Object *o)
{
	return 4;
}

std::string DocumentedType_INT32::typeName()
{
	return "INT32";
}

Object* DocumentedType_INT32::validate(Object *item)
{
	Integer *i = dynamic_cast<Integer*>(item);
	if (i != NULL)
	{
		return i;
	}
	else
	{
		throw SchemaException(item->toString() + " is not an Integer.");
	}
}

std::string DocumentedType_INT32::documentation()
{
	return "Represents an integer between -2<sup>31</sup> and 2<sup>31</sup>-1 inclusive. "
		"The values are encoded using four bytes in network byte order (big-endian).";
}

//----------------------------------------------------------------------

void DocumentedType_UNSIGNED_INT32::write(ByteBuffer *buffer, Object *o)
{
	ByteUtils::writeUnsignedInt(buffer, *(Long*)o);
}

Object* DocumentedType_UNSIGNED_INT32::read(ByteBuffer *buffer)
{
	Long *l = new Long(ByteUtils::readUnsignedInt(buffer));
	return l;
}

int DocumentedType_UNSIGNED_INT32::sizeOf(Object *o)
{
	return 4;
}

std::string DocumentedType_UNSIGNED_INT32::typeName()
{
	return "UINT32";
}

Object* DocumentedType_UNSIGNED_INT32::validate(Object *item)
{
	Long *l = dynamic_cast<Long*>(item);
	if (l != NULL)
	{
		return l;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a Long.");
	}
}

std::string DocumentedType_UNSIGNED_INT32::documentation()
{
	return "Represents an integer between 0 and 2<sup>32</sup>-1 inclusive. "
		"The values are encoded using four bytes in network byte order (big-endian).";
}

//----------------------------------------------------------------------

void DocumentedType_INT64::write(ByteBuffer *buffer, Object *o)
{
	buffer->putLong(*(Long*)o);
}

Object* DocumentedType_INT64::read(ByteBuffer *buffer)
{
	Long *l = new Long(buffer->getLong());
	return l;
}

int DocumentedType_INT64::sizeOf(Object *o)
{
	return 8;
}

std::string DocumentedType_INT64::typeName()
{
	return "INT64";
}

Object* DocumentedType_INT64::validate(Object *item)
{
	Long *l = dynamic_cast<Long*>(item);
	if (l != NULL)
	{
		return l;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a Long.");
	}
}

std::string DocumentedType_INT64::documentation()
{
	return "Represents an integer between -2<sup>63</sup> and 2<sup>63</sup>-1 inclusive. "
		"The values are encoded using eight bytes in network byte order (big-endian).";
}

//----------------------------------------------------------------------

void DocumentedType_STRING::write(ByteBuffer *buffer, Object *o)
{
	ByteArray *bytes = Utils::utf8((String*)o);
	if ((int)*bytes > Short::MAX_VALUE)
		throw SchemaException("String length " + std::to_string(*bytes) + " is larger than the maximum string length.");
	buffer->putShort((short)*bytes);
	buffer->put(bytes);
}

Object* DocumentedType_STRING::read(ByteBuffer *buffer)
{
	short length = buffer->getShort();
	if (length < 0)
		throw SchemaException("String length " + std::to_string(length) + " cannot be negative");
	if (length > buffer->remaining())
		throw SchemaException("Error reading string of length " + std::to_string(length) + ", only " + std::to_string(buffer->remaining()) + " bytes available");
	String *result = Utils::utf8(buffer, length);
	buffer->position(buffer->position() + length);
	return result;
}

int DocumentedType_STRING::sizeOf(Object *o)
{
	return 2 + Utils::utf8Length((String*)o);
}

std::string DocumentedType_STRING::typeName()
{
	return "STRING";
}

Object* DocumentedType_STRING::validate(Object *item)
{
	String *s = dynamic_cast<String*>(item);
	if (s != NULL)
	{
		return s;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a String.");
	}
}

std::string DocumentedType_STRING::documentation()
{
	std::string str = "Represents a sequence of characters. First the length N is given as an ";
	str += Type::INT16()->toString();
	str += ". Then N bytes follow which are the UTF-8 encoding of the character sequence. "
		"Length must not be negative.";
	return str;
}

//----------------------------------------------------------------------

void DocumentedType_NULLABLE_STRING::write(ByteBuffer *buffer, Object *o)
{
	if (o == NULL)
	{
		buffer->putShort(-1);
		return;
	}

	ByteArray *bytes = Utils::utf8((String*)o);
	if (*bytes > Short::MAX_VALUE)
		throw SchemaException("String length " + std::to_string(*bytes) + " is larger than the maximum string length.");
	buffer->putShort((short)*bytes);
	buffer->put(bytes);
}

Object* DocumentedType_NULLABLE_STRING::read(ByteBuffer *buffer)
{
	short length = buffer->getShort();
	if (length < 0)
		return NULL;
	if (length > buffer->remaining())
		throw SchemaException("Error reading string of length " + std::to_string(length) + ", only " + std::to_string(buffer->remaining()) + " bytes available");
	String *result = Utils::utf8(buffer, length);
	buffer->position(buffer->position() + length);
	return result;
}

int DocumentedType_NULLABLE_STRING::sizeOf(Object *o)
{
	if (o == NULL)
		return 2;

	return 2 + Utils::utf8Length((String*)o);
}

std::string DocumentedType_NULLABLE_STRING::typeName()
{
	return "NULLABLE_STRING";
}

Object* DocumentedType_NULLABLE_STRING::validate(Object *item)
{
	if (item == NULL)
		return NULL;

	String *s = dynamic_cast<String*>(item);
	if (s != NULL)
	{
		return s;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a String.");
	}
}

std::string DocumentedType_NULLABLE_STRING::documentation()
{
	std::string str = "Represents a sequence of characters or null. For non-null strings, first the length N is given as an ";
	str += Type::INT16()->toString();
	str += ". Then N bytes follow which are the UTF-8 encoding of the character sequence. "
		"A null value is encoded with length of -1 and there are no following bytes.";
	return str;
}

//----------------------------------------------------------------------

void DocumentedType_BYTES::write(ByteBuffer *buffer, Object *o)
{
	ByteBuffer *arg = (ByteBuffer*)o;
	int pos = arg->position();
	buffer->putInt(arg->remaining());
	buffer->put(arg);
	arg->position(pos);
}

Object* DocumentedType_BYTES::read(ByteBuffer *buffer)
{
	int size = buffer->getInt();
	if (size < 0)
		throw SchemaException("Bytes size " + std::to_string(size) + " cannot be negative");
	if (size > buffer->remaining())
		throw SchemaException("Error reading bytes of size " + std::to_string(size) + ", only " + std::to_string(buffer->remaining()) + " bytes available");

	ByteBuffer *val = buffer->slice();
	val->limit(size);
	buffer->position(buffer->position() + size);
	return val;
}

int DocumentedType_BYTES::sizeOf(Object *o)
{
	ByteBuffer *buffer = (ByteBuffer*)o;
	return 4 + buffer->remaining();
}

std::string DocumentedType_BYTES::typeName()
{
	return "BYTES";
}

Object* DocumentedType_BYTES::validate(Object *item)
{
	ByteBuffer *s = dynamic_cast<ByteBuffer*>(item);
	if (s != NULL)
	{
		return s;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a java.nio.ByteBuffer.");
	}
}

std::string DocumentedType_BYTES::documentation()
{
	std::string str = "Represents a raw sequence of bytes. First the length N is given as an ";
	str += Type::INT32()->toString();
	str += ". Then N bytes follow.";
	return str;
}

//----------------------------------------------------------------------

void DocumentedType_NULLABLE_BYTES::write(ByteBuffer *buffer, Object *o)
{
	if (o == NULL)
	{
		buffer->putInt(-1);
		return;
	}

	ByteBuffer *arg = (ByteBuffer*)o;
	int pos = arg->position();
	buffer->putInt(arg->remaining());
	buffer->put(arg);
	arg->position(pos);
}

Object* DocumentedType_NULLABLE_BYTES::read(ByteBuffer *buffer)
{
	int size = buffer->getInt();
	if (size < 0)
		return NULL;
	if (size > buffer->remaining())
		throw SchemaException("Error reading bytes of size " + std::to_string(size) + ", only " + std::to_string(buffer->remaining()) + " bytes available");

	ByteBuffer *val = buffer->slice();
	val->limit(size);
	buffer->position(buffer->position() + size);
	return val;
}

int DocumentedType_NULLABLE_BYTES::sizeOf(Object *o)
{
	if (o == NULL)
		return 4;

	ByteBuffer *buffer = (ByteBuffer*)o;
	return 4 + buffer->remaining();
}

std::string DocumentedType_NULLABLE_BYTES::typeName()
{
	return "NULLABLE_BYTES";
}

Object* DocumentedType_NULLABLE_BYTES::validate(Object *item)
{
	if (item == NULL)
		return NULL;

	ByteBuffer *s = dynamic_cast<ByteBuffer*>(item);
	if (s != NULL)
	{
		return s;
	}
	else
	{
		throw SchemaException(item->toString() + " is not a java.nio.ByteBuffer.");
	}
}

std::string DocumentedType_NULLABLE_BYTES::documentation()
{
	std::string str = "Represents a raw sequence of bytes or null. For non-null values, first the length N is given as an ";
	str += Type::INT32()->toString();
	str += ". Then N bytes follow. A null value is encoded with length of -1 and there are no following bytes.";
	return str;
}

//----------------------------------------------------------------------

void DocumentedType_RECORDS::write(ByteBuffer *buffer, Object *o)
{

}

Object* DocumentedType_RECORDS::read(ByteBuffer *buffer)
{
	return NULL;
}

int DocumentedType_RECORDS::sizeOf(Object *o)
{
	if (o == NULL)
		return 4;

	BaseRecords *records = (BaseRecords*)o;
	return 4 + records->sizeInBytes();
}

std::string DocumentedType_RECORDS::typeName()
{
	return "RECORDS";
}

Object* DocumentedType_RECORDS::validate(Object *item)
{
	if (item == NULL)
		return NULL;

	BaseRecords *r = dynamic_cast<BaseRecords*>(item);
	if (r != NULL)
	{
		return r;
	}
	else
	{
		throw SchemaException(item->toString() + " is not an instance of Records");
	}
}

std::string DocumentedType_RECORDS::documentation()
{
	std::string str = "Represents a sequence of Kafka records as ";
	str += Type::NULLABLE_BYTES()->toString();
	str += "For a detailed description of records see "
		"<a href=\"/documentation/#messageformat\">Message Sets</a>.";
	return str;
}

//----------------------------------------------------------------------

void DocumentedType_VARINT::write(ByteBuffer *buffer, Object *o)
{
	ByteUtils::writeVarint(*(Integer*)o, buffer);
}

Object* DocumentedType_VARINT::read(ByteBuffer *buffer)
{
	Integer *i = new Integer(ByteUtils::readVarint(buffer));
	return i;
}

int DocumentedType_VARINT::sizeOf(Object *o)
{
	return ByteUtils::sizeOfVarint(*(Integer*)o);
}

std::string DocumentedType_VARINT::typeName()
{
	return "VARINT";
}

Object* DocumentedType_VARINT::validate(Object *item)
{
	Integer *i = dynamic_cast<Integer*>(item);
	if (i != NULL)
	{
		return i;
	}
	else
	{
		throw SchemaException(item->toString() + " is not an integer");
	}
}

std::string DocumentedType_VARINT::documentation()
{
	return "Represents an integer between -2<sup>31</sup> and 2<sup>31</sup>-1 inclusive. "
		"Encoding follows the variable-length zig-zag encoding from "
		" <a href=\"http://code.google.com/apis/protocolbuffers/docs/encoding.html\"> Google Protocol Buffers</a>.";
}

//----------------------------------------------------------------------

void DocumentedType_VARLONG::write(ByteBuffer *buffer, Object *o)
{
	ByteUtils::writeVarlong(*(Long*)o, buffer);
}

Object* DocumentedType_VARLONG::read(ByteBuffer *buffer)
{
	Long *l = new Long(ByteUtils::readVarlong(buffer));
	return l;
}

int DocumentedType_VARLONG::sizeOf(Object *o)
{
	return ByteUtils::sizeOfVarlong(*(Long*)o);;
}

std::string DocumentedType_VARLONG::typeName()
{
	return "VARLONG";
}

Object* DocumentedType_VARLONG::validate(Object *item)
{
	Long *i = dynamic_cast<Long*>(item);
	if (i != NULL)
	{
		return i;
	}
	else
	{
		throw SchemaException(item->toString() + " is not an long");
	}
}

std::string DocumentedType_VARLONG::documentation()
{
	return "Represents an integer between -2<sup>63</sup> and 2<sup>63</sup>-1 inclusive. "
		"Encoding follows the variable-length zig-zag encoding from "
		" <a href=\"http://code.google.com/apis/protocolbuffers/docs/encoding.html\"> Google Protocol Buffers</a>.";
}
