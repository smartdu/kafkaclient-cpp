#include "RequestUtils.h"
#include "RecordBatch.h"
#include "Integer.h"
#include "Struct.h"
#include "Field.h"
#include <stdio.h>

Integer* RequestUtils::getLeaderEpoch(Struct *s, Int32 *leaderEpochField)
{
	int leaderEpoch = *s->getOrElse(leaderEpochField, RecordBatch::NO_PARTITION_LEADER_EPOCH);
	Integer *leaderEpochOpt = (leaderEpoch == RecordBatch::NO_PARTITION_LEADER_EPOCH ?
		NULL : new Integer(leaderEpoch));
	return leaderEpochOpt;
}

void RequestUtils::setLeaderEpochIfExists(Struct *s, Int32 *leaderEpochField, Integer *leaderEpoch)
{
	s->setIfExists(leaderEpochField, leaderEpoch == NULL ? new Integer(RecordBatch::NO_PARTITION_LEADER_EPOCH) : leaderEpoch);
}