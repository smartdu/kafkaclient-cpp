#include "Utils.h"
#include <stdio.h>
#include "ByteArray.h"
#include "String0.h"

ByteArray* Utils::utf8(String *o)
{
	ByteArray *b = new ByteArray(o);
	return b;
}

String* Utils::utf8(ByteBuffer *buffer, int length)
{
	return NULL;
}

int Utils::utf8Length(String *o)
{
	return 0;
}
