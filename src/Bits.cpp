#include "Bits.h"
#include "ByteBuffer.h"

void Bits::putShort(ByteBuffer *bb, int bi, short x, bool bigEndian)
{
	if (bigEndian)
		putShortB(bb, bi, x);
	else
		putShortL(bb, bi, x);
}

short Bits::getShort(ByteBuffer *bb, int bi, bool bigEndian)
{
	return bigEndian ? getShortB(bb, bi) : getShortL(bb, bi);
}

void Bits::putInt(ByteBuffer *bb, int bi, int x, bool bigEndian)
{
	if (bigEndian)
		putIntB(bb, bi, x);
	else
		putIntL(bb, bi, x);
}

int Bits::getInt(ByteBuffer *bb, int bi, bool bigEndian)
{
	return bigEndian ? getIntB(bb, bi) : getIntL(bb, bi);
}

void Bits::putLong(ByteBuffer *bb, int bi, long long x, bool bigEndian)
{
	if (bigEndian)
		putLongB(bb, bi, x);
	else
		putLongL(bb, bi, x);
}

long long Bits::getLong(ByteBuffer *bb, int bi, bool bigEndian)
{
	return bigEndian ? getLongB(bb, bi) : getLongL(bb, bi);
}

short Bits::getShortB(ByteBuffer *bb, int bi)
{
	return makeShort(bb->_get(bi),
		bb->_get(bi + 1));
}

short Bits::getShortL(ByteBuffer *bb, int bi)
{
	return makeShort(bb->_get(bi + 1),
		bb->_get(bi));
}

void Bits::putShortB(ByteBuffer *bb, int bi, short x)
{
	bb->_put(bi, short1(x));
	bb->_put(bi + 1, short0(x));
}

void Bits::putShortL(ByteBuffer *bb, int bi, short x)
{
	bb->_put(bi, short0(x));
	bb->_put(bi + 1, short1(x));
}

void Bits::putIntB(ByteBuffer *bb, int bi, int x)
{
	bb->_put(bi, int3(x));
	bb->_put(bi + 1, int2(x));
	bb->_put(bi + 2, int1(x));
	bb->_put(bi + 3, int0(x));
}

void Bits::putIntL(ByteBuffer *bb, int bi, int x)
{
	bb->_put(bi + 3, int3(x));
	bb->_put(bi + 2, int2(x));
	bb->_put(bi + 1, int1(x));
	bb->_put(bi, int0(x));
}

int Bits::getIntB(ByteBuffer *bb, int bi)
{
	return makeInt(bb->_get(bi),
		bb->_get(bi + 1),
		bb->_get(bi + 2),
		bb->_get(bi + 3));
}

int Bits::getIntL(ByteBuffer *bb, int bi)
{
	return makeInt(bb->_get(bi + 3),
		bb->_get(bi + 2),
		bb->_get(bi + 1),
		bb->_get(bi));
}

void Bits::putLongB(ByteBuffer *bb, int bi, long long x)
{
	bb->_put(bi, long7(x));
	bb->_put(bi + 1, long6(x));
	bb->_put(bi + 2, long5(x));
	bb->_put(bi + 3, long4(x));
	bb->_put(bi + 4, long3(x));
	bb->_put(bi + 5, long2(x));
	bb->_put(bi + 6, long1(x));
	bb->_put(bi + 7, long0(x));
}

void Bits::putLongL(ByteBuffer *bb, int bi, long long x)
{
	bb->_put(bi + 7, long7(x));
	bb->_put(bi + 6, long6(x));
	bb->_put(bi + 5, long5(x));
	bb->_put(bi + 4, long4(x));
	bb->_put(bi + 3, long3(x));
	bb->_put(bi + 2, long2(x));
	bb->_put(bi + 1, long1(x));
	bb->_put(bi, long0(x));
}

long long Bits::getLongB(ByteBuffer *bb, int bi)
{
	return makeLong(bb->_get(bi),
		bb->_get(bi + 1),
		bb->_get(bi + 2),
		bb->_get(bi + 3),
		bb->_get(bi + 4),
		bb->_get(bi + 5),
		bb->_get(bi + 6),
		bb->_get(bi + 7));
}

long long Bits::getLongL(ByteBuffer *bb, int bi)
{
	return makeLong(bb->_get(bi + 7),
		bb->_get(bi + 6),
		bb->_get(bi + 5),
		bb->_get(bi + 4),
		bb->_get(bi + 3),
		bb->_get(bi + 2),
		bb->_get(bi + 1),
		bb->_get(bi));
}

long long Bits::makeLong(char b7, char b6, char b5, char b4,
	char b3, char b2, char b1, char b0)
{
	return ((((long long)b7) << 56) |
		(((long long)b6 & 0xff) << 48) |
		(((long long)b5 & 0xff) << 40) |
		(((long long)b4 & 0xff) << 32) |
		(((long long)b3 & 0xff) << 24) |
		(((long long)b2 & 0xff) << 16) |
		(((long long)b1 & 0xff) << 8) |
		(((long long)b0 & 0xff)));
}