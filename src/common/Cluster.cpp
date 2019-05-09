#include "Cluster.h"
#include "Node.h"

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> internalTopics)
{
	new (this)Cluster(clusterId, false, nodes, partitions, unauthorizedTopics, std::set<std::string>(), internalTopics, NULL);
}

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
	new (this)Cluster(clusterId, false, nodes, partitions, unauthorizedTopics, std::set<std::string>(), internalTopics, controller);
}

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> invalidTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
	new (this)Cluster(clusterId, false, nodes, partitions, unauthorizedTopics, invalidTopics, internalTopics, controller);
}

Cluster::Cluster(const char *clusterId,
	bool isBootstrapConfigured,
	std::list<Node*> nodes,
	std::list<PartitionInfo> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> invalidTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
	this->isBootstrapConfigured = isBootstrapConfigured;
	this->clusterResource = new ClusterResource(clusterId);
	this->nodes = nodes;

	std::map<int, Node*> tmpNodesById;
	for (auto iter : nodes)
		tmpNodesById[iter->id()] = iter;
	this->nodesById_ = tmpNodesById;

	std::map<TopicPartition, PartitionInfo> tmpPartitionsByTopicPartition;
	std::map<std::string, std::list<PartitionInfo>> tmpPartitionsByTopic;
	std::map<std::string, std::list<PartitionInfo>> tmpAvailablePartitionsByTopic;
	std::map<int, std::list<PartitionInfo>> tmpPartitionsByNode;
	for (PartitionInfo p : partitions)
	{
		tmpPartitionsByTopicPartition[TopicPartition(p.topic(), p.partition())] = p;
		tmpPartitionsByTopic.merge(p.topic(), Collections.singletonList(p), Utils::concatListsUnmodifiable);
		if (p.leader() != null)
		{
			tmpAvailablePartitionsByTopic.merge(p.topic(), Collections.singletonList(p), Utils::concatListsUnmodifiable);
			tmpPartitionsByNode.merge(p.leader().id(), Collections.singletonList(p), Utils::concatListsUnmodifiable);
		}
	}
	this->partitionsByTopicPartition_ = tmpPartitionsByTopicPartition;
	this->partitionsByTopic_ = tmpPartitionsByTopic;
	this->availablePartitionsByTopic_ = tmpAvailablePartitionsByTopic;
	this->partitionsByNode_ = tmpPartitionsByNode;

	this->unauthorizedTopics_ = unauthorizedTopics;
	this->invalidTopics_ = invalidTopics;
	this->internalTopics_ = internalTopics;
	this->controller_ = controller;
}

Cluster* Cluster::empty()
{
	new Cluster(NULL, std::list<Node*>(), std::list<PartitionInfo>(), std::set<std::string>(),
		std::set<std::string>(), NULL);
}

Cluster* Cluster::bootstrap(std::list<InetSocketAddress> addresses)
{
	std::list<Node*> nodes;
	int nodeId = -1;
	for (InetSocketAddress address : addresses)
		nodes.push_back(new Node(nodeId--, address.getHostString(), address.getPort()));
	return new Cluster(NULL, true, nodes, std::list<PartitionInfo>(),
		std::set<std::string>(), std::set<std::string>(), std::set<std::string>(), NULL);
}

Cluster* Cluster::withPartitions(std::map<TopicPartition, PartitionInfo> partitions)
{
	std::map<TopicPartition, PartitionInfo> combinedPartitions;
	combinedPartitions.swap(partitions);
	return new Cluster(clusterResource_.clusterId(), this->nodes_, combinedPartitions.values(),
		this->unauthorizedTopics_, this->invalidTopics_,
		this->internalTopics_, this->controller_);
}