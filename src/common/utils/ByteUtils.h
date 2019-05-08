#ifndef __KFK_BYTEUTILS_H__
#define __KFK_BYTEUTILS_H__

#pragma once
class ByteBuffer;

class ByteUtils
{
public:
	static void writeUnsignedInt(ByteBuffer *buffer, long long value);

	static long long readUnsignedInt(ByteBuffer *buffer);

	static void writeVarint(int value, ByteBuffer *buffer);

	static int readVarint(ByteBuffer *buffer);

	static int sizeOfVarint(int value);

	static void writeVarlong(long long value, ByteBuffer *buffer);

	static long long readVarlong(ByteBuffer *buffer);

	static int sizeOfVarlong(long long value);
};

#endif // !__KFK_BYTEUTILS_H__
