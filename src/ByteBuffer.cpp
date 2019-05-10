#include "ByteBuffer.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "ByteArray.h"
#include "IllegalArgumentException.h"
#include "BufferUnderflowException.h"
#include "BufferOverflowException.h"
#include "Bits.h"
#include <string.h>

ByteBuffer::~ByteBuffer()
{
	if (hb_ != NULL)
		free(hb_);
}

ByteBuffer* ByteBuffer::allocate(int capacity)
{
	if (capacity < 0)
		throw IllegalArgumentException("");
	return new ByteBuffer(capacity, capacity);
}

int ByteBuffer::position()
{
	return position_;
}

ByteBuffer* ByteBuffer::position(int p)
{
	if ((p > limit_) || (p < 0))
		throw IllegalArgumentException("");
	position_ = p;
	if (mark_ > position_)
		mark_ = -1;
	return this;
}

int ByteBuffer::remaining()
{
	return limit_ - position_;
}

int ByteBuffer::capacity()
{
	return capacity_;
}

void ByteBuffer::put(ByteBuffer *sb)
{
	int n = sb->remaining();
	if (n > remaining())
		throw BufferOverflowException("");
	memcpy(hb_ + ix(position()), sb->hb_ + sb->ix(sb->position()), n);
	sb->position(position() + n);
	position(position() + n);
}

ByteBuffer* ByteBuffer::put(char c)
{
	hb_[ix(nextPutIndex())] = c;
	return this;
}

char ByteBuffer::get()
{
	return hb_[ix(nextGetIndex())];
}

ByteBuffer* ByteBuffer::putShort(short value)
{
	Bits::putShort(this, ix(nextPutIndex(2)), value, bigEndian_);
	return this;
}

short ByteBuffer::getShort()
{
	return Bits::getShort(this, ix(nextGetIndex(2)), bigEndian_);
}

ByteBuffer* ByteBuffer::putInt(int value)
{
	Bits::putInt(this, ix(nextPutIndex(4)), value, bigEndian_);
	return this;
}

int ByteBuffer::getInt()
{
	return Bits::getInt(this, ix(nextGetIndex(4)), bigEndian_);
}

ByteBuffer* ByteBuffer::putLong(long long value)
{
	Bits::putLong(this, ix(nextPutIndex(8)), value, bigEndian_);
	return this;
}

long long ByteBuffer::getLong()
{
	return Bits::getLong(this, ix(nextGetIndex(8)), bigEndian_);
}

ByteBuffer* ByteBuffer::put(ByteArray *src)
{
	put(src, 0, *src);
	return this;
}

ByteBuffer* ByteBuffer::put(ByteArray *src, int offset, int length)
{
	if (length > remaining())
		throw BufferOverflowException("");
	int end = offset_ + length;
	for (int i = offset_; i < end; i++)
		this->put((*src)[i]);
	return this;
}

ByteBuffer* ByteBuffer::slice()
{
	return new ByteBuffer(hb_, -1, 0, remaining(), remaining(), position() + offset_);
}

ByteBuffer* ByteBuffer::limit(int l)
{
	if ((l > capacity_) || (l < 0))
		throw IllegalArgumentException("");
	limit_ = l;
	if (position_ > limit_)
		position_ = limit_;
	if (mark_ > limit_)
		mark_ = -1;
	return this;
}

int ByteBuffer::limit()
{
	return limit_;
}

ByteBuffer* ByteBuffer::rewind()
{
	position_ = 0;
	mark_ = -1;
	return this;
}

ByteBuffer* ByteBuffer::mark()
{
	mark_ = position_;
	return this;
}

ByteBuffer* ByteBuffer::wrap(ByteArray *array, int offset, int length)
{
	return new ByteBuffer((char*)*array, *array, offset, length);
}

ByteBuffer* ByteBuffer::wrap(ByteArray *array)
{
	return wrap(array, 0, *array);
}

ByteBuffer* ByteBuffer::wrap(char *buf, int length)
{
	return new ByteBuffer(buf, length, 0, length);
}

ByteBuffer* ByteBuffer::get(ByteArray *dst, int offset, int length)
{
	if (length > remaining())
		throw BufferUnderflowException("");
	int end = offset_ + length;
	for (int i = offset_; i < end; i++)
		(*dst)[i] = get();
	return this;
}

ByteBuffer* ByteBuffer::get(ByteArray *dst)
{
	return get(dst, 0, *dst);
}

int ByteBuffer::ix(int i)
{
	return i + offset_;
}

ByteBuffer::ByteBuffer(int cap, int lim)
{
	new (this)ByteBuffer(-1, 0, lim, cap, (char*)malloc(cap), 0);
}

ByteBuffer::ByteBuffer(int mark, int pos, int lim, int cap)
{
	mark_ = -1;
	bigEndian_ = true;

	if (cap < 0)
		throw IllegalArgumentException("Negative capacity: " + cap);
	this->capacity_ = cap;
	limit(lim);
	position(pos);
	if (mark >= 0)
	{
		if (mark > pos)
			throw IllegalArgumentException("mark > position: ("
				+ std::to_string(mark) + " > " + std::to_string(pos) + ")");
		this->mark_ = mark;
	}
}

ByteBuffer::ByteBuffer(char *buf, int size, int off, int len)
{
	new (this)ByteBuffer(-1, off, off + len, size, buf, 0);
}

ByteBuffer::ByteBuffer(int mark, int pos, int lim, int cap, char *hb, int offset)
{
	new (this)ByteBuffer(mark, pos, lim, cap);
	hb_ = hb;
	offset_ = offset;
}

ByteBuffer::ByteBuffer(char *buf, int mark, int pos, int lim, int cap, int off)
{
	new (this)ByteBuffer(mark, pos, lim, cap, buf, off);
}

int ByteBuffer::nextGetIndex()
{
	if (position_ >= limit_)
		throw BufferUnderflowException("");
	return position_++;
}

int ByteBuffer::nextGetIndex(int nb)
{
	if (limit_ - position_ < nb)
		throw BufferUnderflowException("");
	int p = position_;
	position_ += nb;
	return p;
}

int ByteBuffer::nextPutIndex()
{
	if (position_ >= limit_)
		throw BufferOverflowException("");
	return position_++;
}

int ByteBuffer::nextPutIndex(int nb)
{
	if (limit_ - position_ < nb)
		throw BufferOverflowException("");
	int p = position_;
	position_ += nb;
	return p;
}

char ByteBuffer::_get(int i)
{
	return hb_[i];
}

void ByteBuffer::_put(int i, char b)
{
	hb_[i] = b;
}
