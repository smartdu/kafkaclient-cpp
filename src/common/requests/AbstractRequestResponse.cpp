#include "AbstractRequestResponse.h"
#include "ByteBuffer.h"
#include "Struct.h"

ByteBuffer* AbstractRequestResponse::serialize(Struct *headerStruct, Struct *bodyStruct)
{
	ByteBuffer *buffer = ByteBuffer::allocate(headerStruct->sizeOf() + bodyStruct->sizeOf());
	headerStruct->writeTo(buffer);
	bodyStruct->writeTo(buffer);
	buffer->rewind();
	return buffer;
}