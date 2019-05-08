#ifndef __KFK_BYTEBUFFER_H__
#define __KFK_BYTEBUFFER_H__

#pragma once
class Short;
class Integer;
class Long;
class ByteArray;
#include "Object.h"

class ByteBuffer
	: public Object
{
public:
	friend class Bits;
	virtual ~ByteBuffer();

	static ByteBuffer* allocate(int capacity);

	int position();
	ByteBuffer* position(int p);

	int remaining();

	int capacity();

	void put(ByteBuffer *o);

	ByteBuffer* put(char c);
	char get();

	ByteBuffer* putShort(short value);
	short getShort();

	ByteBuffer* putInt(int value);
	int getInt();

	ByteBuffer* putLong(long long value);
	long long getLong();

	ByteBuffer* put(ByteArray *src);

	ByteBuffer* put(ByteArray *src, int offset, int length);

	ByteBuffer* slice();

	ByteBuffer* limit(int l);

	int limit();

	ByteBuffer* rewind();

	ByteBuffer* mark();

	static ByteBuffer* wrap(ByteArray *array, int offset, int length);
	static ByteBuffer* wrap(ByteArray *array);
	static ByteBuffer* wrap(char *buf, int length);

	ByteBuffer* get(ByteArray *dst);
	ByteBuffer* get(ByteArray *dst, int offset, int length);

protected:
	int ix(int i);

	ByteBuffer(int cap, int lim);
	ByteBuffer(int mark, int pos, int lim, int cap);
	ByteBuffer(char *buf, int size, int off, int len);
	ByteBuffer(int mark, int pos, int lim, int cap, char *hb, int offset);
	ByteBuffer(char *buf, int mark, int pos, int lim, int cap, int off);

private:
	int nextGetIndex();

	int nextGetIndex(int nb);

	int nextPutIndex();

	int nextPutIndex(int nb);

	char _get(int i);

	void _put(int i, char b);

private:
	int mark_;
	int position_;
	int limit_;
	int capacity_;
	int offset_;
	bool bigEndian_;

	char *hb_;
};

#endif // !__KFK_BYTEBUFFER_H__
