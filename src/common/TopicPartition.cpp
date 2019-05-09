#include "TopicPartition.h"

TopicPartition::TopicPartition(const char *topic, int partition)
	: topic_(topic)
	, partition_(partition)
{

}

std::string TopicPartition::toString()
{
	return topic_ + "-" + std::to_string(partition_);
}