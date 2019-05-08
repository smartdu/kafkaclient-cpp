#ifndef __KFK_BITS_H__
#define __KFK_BITS_H__

#pragma once
class ByteBuffer;

class Bits
{
public:
	static void putShort(ByteBuffer *bb, int bi, short x, bool bigEndian);

	static short getShort(ByteBuffer *bb, int bi, bool bigEndian);

	static void putInt(ByteBuffer *bb, int bi, int x, bool bigEndian);

	static int getInt(ByteBuffer *bb, int bi, bool bigEndian);

	static void putLong(ByteBuffer *bb, int bi, long long x, bool bigEndian);

	static long long getLong(ByteBuffer *bb, int bi, bool bigEndian);

private:
	static short getShortB(ByteBuffer *bb, int bi);

	static short getShortL(ByteBuffer *bb, int bi);

	static void putShortB(ByteBuffer *bb, int bi, short x);

	static void putShortL(ByteBuffer *bb, int bi, short x);

	static void putIntB(ByteBuffer *bb, int bi, int x);

	static void putIntL(ByteBuffer *bb, int bi, int x);

	static int getIntB(ByteBuffer *bb, int bi);

	static int getIntL(ByteBuffer *bb, int bi);

	static void putLongB(ByteBuffer *bb, int bi, long long x);

	static void putLongL(ByteBuffer *bb, int bi, long long x);

	static long long getLongB(ByteBuffer *bb, int bi);

	static long long getLongL(ByteBuffer *bb, int bi);

	static long long makeLong(char b7, char b6, char b5, char b4,
		char b3, char b2, char b1, char b0);

	static char long7(long long x) { return (char)(x >> 56); }
	static char long6(long long x) { return (char)(x >> 48); }
	static char long5(long long x) { return (char)(x >> 40); }
	static char long4(long long x) { return (char)(x >> 32); }
	static char long3(long long x) { return (char)(x >> 24); }
	static char long2(long long x) { return (char)(x >> 16); }
	static char long1(long long x) { return (char)(x >> 8); }
	static char long0(long long x) { return (char)(x); }

	static char int3(int x) { return (char)(x >> 24); }
	static char int2(int x) { return (char)(x >> 16); }
	static char int1(int x) { return (char)(x >> 8); }
	static char int0(int x) { return (char)(x); }

	static char short1(short x) { return (char)(x >> 8); }
	static char short0(short x) { return (char)(x); }

	static int makeInt(char b3, char b2, char b1, char b0) {
		return (((b3) << 24) |
			((b2 & 0xff) << 16) |
			((b1 & 0xff) << 8) |
			((b0 & 0xff)));
	}

	static short makeShort(char b1, char b0) {
		return (short)((b1 << 8) | (b0 & 0xff));
	}
};

#endif // !__KFK_BITS_H__
