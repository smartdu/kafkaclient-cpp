#include "ResponseHeader.h"
#include "Schema.h"
#include "Field.h"
#include "Struct.h"
#include "Integer.h"

Schema* ResponseHeader::SCHEMA = new Schema(1,
	new Field("correlation_id", Type::INT32()->clone(), "The user-supplied value passed in with the request"));

UNINIT_BEGIN(ResponseHeader)
    Schema::destroy(ResponseHeader::SCHEMA);
UNINIT_END(ResponseHeader)

BoundField* ResponseHeader::CORRELATION_KEY_FIELD = SCHEMA->get("correlation_id");

ResponseHeader::ResponseHeader(Struct *s)
{
	Integer *i = s->getInt(CORRELATION_KEY_FIELD);
	correlationId_ = (int)(*i);
}

ResponseHeader::ResponseHeader(int correlationId)
{
	this->correlationId_ = correlationId;
}

int ResponseHeader::sizeOf()
{
	return toStruct()->sizeOf();
}

Struct* ResponseHeader::toStruct()
{
	Struct *s = new Struct(SCHEMA);
	Integer *i = new Integer(correlationId_);
	s->set(CORRELATION_KEY_FIELD, i);
	return s;
}

int ResponseHeader::correlationId()
{
	return correlationId_;
}

ResponseHeader* ResponseHeader::parse(ByteBuffer *buffer)
{
	return new ResponseHeader((Struct*)SCHEMA->read(buffer));
}