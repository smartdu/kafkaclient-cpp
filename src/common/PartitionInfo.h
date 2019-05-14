#ifndef __KFK_PARTITIONINFO_H__
#define __KFK_PARTITIONINFO_H__

#pragma once
#include "Node.h"
#include <list>

class PartitionInfo
{
public:
	PartitionInfo(const char *topic, int partition, Node *leader, std::list<Node*> replicas, std::list<Node*> inSyncReplicas);
	PartitionInfo(const char *topic, int partition, Node *leader, std::list<Node*> replicas, std::list<Node*> inSyncReplicas, std::list<Node*> offlineReplicas);

	const char* topic()
	{
		return topic_.c_str();
	}

	int partition()
	{
		return partition_;
	}

	Node* leader()
	{
		return leader_;
	}

	std::list<Node*> replicas()
	{
		return replicas_;
	}

	std::list<Node*> inSyncReplicas()
	{
		return inSyncReplicas_;
	}

	std::list<Node*> offlineReplicas()
	{
		return offlineReplicas_;
	}

	virtual std::string toString();

private:
	std::string formatNodeIds(std::list<Node*> nodes);

    void init(const char *topic, int partition, Node *leader, std::list<Node*> replicas, std::list<Node*> inSyncReplicas, std::list<Node*> offlineReplicas);

private:
	std::string topic_;
	int partition_;
	Node *leader_;
	std::list<Node*> replicas_;
	std::list<Node*> inSyncReplicas_;
	std::list<Node*> offlineReplicas_;
};

#endif // !__KFK_PARTITIONINFO_H__
