#ifndef __KFK_REQUESTUTILS_H__
#define __KFK_REQUESTUTILS_H__

#pragma once
class Integer;
class Struct;
class Int32;

class RequestUtils
{
public:
	static Integer* getLeaderEpoch(Struct *s, Int32 *leaderEpochField);

	static void setLeaderEpochIfExists(Struct *s, Int32 *leaderEpochField, Integer *leaderEpoch);
};

#endif // !__KFK_REQUESTUTILS_H__
