#include "Utils.h"
#include <stdio.h>
#include <list>
#include <map>
#include "ByteArray.h"
#include "String0.h"
#include "Character.h"
#include "ByteBuffer.h"

ByteArray* Utils::utf8(String *o)
{
	ByteArray *b = new ByteArray(o);
	return b;
}

String* Utils::utf8(ByteBuffer *buffer, int length)
{
	return utf8(buffer, 0, length);
}

String* Utils::utf8(ByteBuffer *buffer)
{
	return utf8(buffer, buffer->remaining());
}

String* Utils::utf8(ByteBuffer *buffer, int offset, int length)
{
	return new String(buffer->array(), buffer->arrayOffset() + buffer->position() + offset, length);
}

int Utils::utf8Length(String *s)
{
	int count = 0;
	for (int i = 0, len = *s; i < len; i++)
	{
		char ch = s[i];
		if (ch <= 0x7F)
		{
			count++;
		}
		else if (ch <= 0x7FF)
		{
			count += 2;
		}
		else if (false/*Character::isHighSurrogate(ch)*/)
		{
			count += 4;
			++i;
		}
		else
		{
			count += 3;
		}
	}
	return count;
}
