#ifndef __KFK_RECORDBATCH_H__
#define __KFK_RECORDBATCH_H__

#pragma once

class RecordBatch
{
public:
	static const char MAGIC_VALUE_V0 = 0;
	static const char MAGIC_VALUE_V1 = 1;
	static const char MAGIC_VALUE_V2 = 2;

	static const char CURRENT_MAGIC_VALUE = MAGIC_VALUE_V2;

	static const int NO_PARTITION_LEADER_EPOCH = -1;
};

#endif // !__KFK_RECORDBATCH_H__
