#ifndef __KFK_PATTERNTYPE_H__
#define __KFK_PATTERNTYPE_H__

#pragma once

class PatternType
{
public:
	static const char UNKNOWN = 0;
	static const char ANY = 1;
	static const char MATCH = 2;
	static const char LITERAL = 3;
	static const char PREFIXED = 4;
};

#endif // !__KFK_PATTERNTYPE_H__
