#include "ByteBuffer.h"
#include "IllegalArgumentException.h"
#include "ByteUtils.h"

#define CLEAR_BIT(_n_)	\
	 _n_ = (_n_ & ~(1UL << (sizeof(_n_)*8-1)))
#define CLEAR_BIT1(_n_)	\
	(_n_ & ~(1UL << (sizeof(_n_)*8-1)))

static IllegalArgumentException illegalVarintException(int value) {
	throw IllegalArgumentException("Varint is too long, the most significant bit in the 5th byte is set, "
		"converted value: " + std::to_string(value));
}

static IllegalArgumentException illegalVarlongException(long long value) {
	throw new IllegalArgumentException("Varlong is too long, most significant bit in the 10th byte is set, "
		"converted value: " + std::to_string(value));
}

void ByteUtils::writeUnsignedInt(ByteBuffer *buffer, long long value)
{
	buffer->putInt((int)(value & 0xffffffffL));
}

long long ByteUtils::readUnsignedInt(ByteBuffer *buffer)
{
	return buffer->getInt() & 0xffffffffL;
}

void ByteUtils::writeVarint(int value, ByteBuffer *buffer)
{
	int v = (value << 1) ^ (value >> 31);
	while ((v & 0xffffff80) != 0L)
	{
		char b = (char)((v & 0x7f) | 0x80);
		buffer->put(b);
		v >>= 7;
		CLEAR_BIT(v);
	}
	buffer->put((char)v);
}

int ByteUtils::readVarint(ByteBuffer *buffer)
{
	int value = 0;
	int i = 0;
	int b;
	while (((b = buffer->get()) & 0x80) != 0) {
		value |= (b & 0x7f) << i;
		i += 7;
		if (i > 28)
			throw illegalVarintException(value);
	}
	value |= b << i;
	int tmp = (value >> 1);
	return CLEAR_BIT1(tmp) ^ -(value & 1);
}

int ByteUtils::sizeOfVarint(int value)
{
	int v = (value << 1) ^ (value >> 31);
	int bytes = 1;
	while ((v & 0xffffff80) != 0L)
	{
		bytes += 1;
		v >>= 7;
		CLEAR_BIT(v);
	}
	return bytes;
}

void ByteUtils::writeVarlong(long long value, ByteBuffer *buffer)
{
	long long v = (value << 1) ^ (value >> 63);
	while ((v & 0xffffffffffffff80L) != 0L)
	{
		char b = (char)((v & 0x7f) | 0x80);
		buffer->put(b);
		v >>= 7;
		CLEAR_BIT(v);
	}
	buffer->put((char)v);
}

long long ByteUtils::readVarlong(ByteBuffer *buffer)
{
	long long value = 0L;
	int i = 0;
	long long b;
	while (((b = buffer->get()) & 0x80) != 0)
	{
		value |= (b & 0x7f) << i;
		i += 7;
		if (i > 63)
			throw illegalVarlongException(value);
	}
	value |= b << i;
	long long tmp = value >> 1;
	return (CLEAR_BIT1(tmp)) ^ -(value & 1);
}

int ByteUtils::sizeOfVarlong(long long value)
{
	long long v = (value << 1) ^ (value >> 63);
	int bytes = 1;
	while ((v & 0xffffffffffffff80L) != 0L)
	{
		bytes += 1;
		v >>= 7;
		CLEAR_BIT(v);
	}
	return bytes;
}
