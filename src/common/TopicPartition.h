#ifndef __KFK_TOPICPARTITION_H__
#define __KFK_TOPICPARTITION_H__

#pragma once
#include <string>
#include "Object.h"

class TopicPartition
	: public Object
{
public:
	TopicPartition(const char *topic, int partition);

	int partition()
	{
		return partition_;
	}

	const char* topic()
	{
		return topic_.c_str();
	}

	virtual std::string toString();

private:
	int partition_;
	std::string topic_;
};

#endif // !__KFK_TOPICPARTITION_H__
