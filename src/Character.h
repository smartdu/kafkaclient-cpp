#ifndef __KFK_CHARACTER_H__
#define __KFK_CHARACTER_H__

#pragma once

class Character
{
public:
	static const wchar_t MIN_HIGH_SURROGATE = 0xD800;

	static const wchar_t MAX_HIGH_SURROGATE = 0xDBFF;

	static bool isHighSurrogate(char ch);
};

#endif // !__KFK_BYTEBUFFER_H__
