#ifndef __KFK_CLUSTER_H__
#define __KFK_CLUSTER_H__

#pragma once
#include <set>
#include <list>
#include <map>
#include "ClusterResource.h"
#include "TopicPartition.h"
#include "PartitionInfo.h"
#include "InetSocketAddress.h"
class Node;
class Integer;

class Cluster
{
public:
	Cluster(const char *clusterId,
		std::list<Node*> nodes,
		std::list<PartitionInfo> partitions,
		std::set<std::string> unauthorizedTopics,
		std::set<std::string> internalTopics);

	Cluster(const char *clusterId,
		std::list<Node*> nodes,
		std::list<PartitionInfo> partitions,
		std::set<std::string> unauthorizedTopics,
		std::set<std::string> internalTopics,
		Node *controller);

	Cluster(const char *clusterId,
		std::list<Node*> nodes,
		std::list<PartitionInfo> partitions,
		std::set<std::string> unauthorizedTopics,
		std::set<std::string> invalidTopics,
		std::set<std::string> internalTopics,
		Node *controller);

	static Cluster* empty();

	static Cluster* bootstrap(std::list<InetSocketAddress> addresses);

	Cluster* withPartitions(std::map<TopicPartition, PartitionInfo> partitions);

	std::list<Node*> nodes()
	{
		return this->nodes_;
	}

	Node* nodeById(int id)
	{
		return this->nodesById_[id];
	}

	Node* leaderFor(TopicPartition topicPartition);

	PartitionInfo partition(TopicPartition topicPartition);

	std::list<PartitionInfo> partitionsForTopic(const char *topic);

	Integer* partitionCountForTopic(const char *topic);

	std::list<PartitionInfo> availablePartitionsForTopic(const char *topic);

	std::list<PartitionInfo> partitionsForNode(int nodeId);

	std::set<std::string> topics();

	std::set<std::string> unauthorizedTopics()
	{
		return unauthorizedTopics_;
	}

	std::set<std::string> invalidTopics()
	{
		return invalidTopics_;
	}

	std::set<std::string> internalTopics() 
	{
		return internalTopics_;
	}

	bool isBootstrapConfigured()
	{
		return isBootstrapConfigured_;
	}

	ClusterResource clusterResource()
	{
		return clusterResource_;
	}

	Node* controller()
	{
		return controller_;
	}

	virtual std::string toString();

private:
	Cluster(const char *clusterId,
		bool isBootstrapConfigured,
		std::list<Node*> nodes,
		std::list<PartitionInfo> partitions,
		std::set<std::string> unauthorizedTopics,
		std::set<std::string> invalidTopics,
		std::set<std::string> internalTopics,
		Node *controller);

private:
	bool isBootstrapConfigured_;
	std::list<Node*> nodes_;
	std::set<std::string> unauthorizedTopics_;
	std::set<std::string> invalidTopics_;
	std::set<std::string> internalTopics_;
	Node *controller_;
	std::map<TopicPartition, PartitionInfo> partitionsByTopicPartition_;
	std::map<std::string, std::list<PartitionInfo>> partitionsByTopic_;
	std::map<std::string, std::list<PartitionInfo>> availablePartitionsByTopic_;
	std::map<int, std::list<PartitionInfo>> partitionsByNode_;
	std::map<int, Node*> nodesById_;
	ClusterResource clusterResource_;
};

#endif // !__KFK_CLUSTER_H__
