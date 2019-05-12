#include "PartitionInfo.h"

PartitionInfo::PartitionInfo(const char *topic, int partition, Node *leader, std::list<Node*> replicas, std::list<Node*> inSyncReplicas)
{
	new (this)PartitionInfo(topic, partition, leader, replicas, inSyncReplicas, std::list<Node*>());
}

PartitionInfo::PartitionInfo(const char *topic, int partition, Node *leader, std::list<Node*> replicas, std::list<Node*> inSyncReplicas, std::list<Node*> offlineReplicas)
{
	this->topic_ = topic;
	this->partition_ = partition;
	this->leader_ = leader;
	this->replicas_ = replicas;
	this->inSyncReplicas_ = inSyncReplicas;
	this->offlineReplicas_ = offlineReplicas;
}

std::string PartitionInfo::toString()
{
	return "Partition(topic = " + topic_ + ", partition = " + std::to_string(partition_) + ", leader = " + (leader_ == NULL ? "none" : leader_->toString()) + ", replicas = " +
		formatNodeIds(replicas_) + ", isr = " + formatNodeIds(inSyncReplicas_) + ", offlineReplicas = " + formatNodeIds(offlineReplicas_) + ")";
}

std::string PartitionInfo::formatNodeIds(std::list<Node*> nodes)
{
	std::string b = "[";
	if (!nodes.empty())
	{
		unsigned int i = 0;
		for (auto iter : nodes)
		{
			b.append(iter->idString());
			if (i < nodes.size() - 1)
				b.append(",");
			i++;
		}
	}
	b.append("]");
	return b;
}
