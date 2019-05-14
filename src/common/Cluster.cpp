#include "Cluster.h"
#include "Node.h"
#include "Integer.h"
#include "Utils.h"

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo*> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> internalTopics)
{
    init(clusterId, false, nodes, partitions, unauthorizedTopics, std::set<std::string>(), internalTopics, NULL);
}

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo*> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
    init(clusterId, false, nodes, partitions, unauthorizedTopics, std::set<std::string>(), internalTopics, controller);
}

Cluster::Cluster(const char *clusterId,
	std::list<Node*> nodes,
	std::list<PartitionInfo*> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> invalidTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
    init(clusterId, false, nodes, partitions, unauthorizedTopics, invalidTopics, internalTopics, controller);
}

Cluster::Cluster(const char *clusterId,
	bool isBootstrapConfigured,
	std::list<Node*> nodes,
	std::list<PartitionInfo*> partitions,
	std::set<std::string> unauthorizedTopics,
	std::set<std::string> invalidTopics,
	std::set<std::string> internalTopics,
	Node *controller)
{
    init(clusterId, isBootstrapConfigured, nodes, partitions, unauthorizedTopics, invalidTopics, internalTopics, controller);
}

void Cluster::init(const char *clusterId,
    bool isBootstrapConfigured,
    std::list<Node*> nodes,
    std::list<PartitionInfo*> partitions,
    std::set<std::string> unauthorizedTopics,
    std::set<std::string> invalidTopics,
    std::set<std::string> internalTopics,
    Node *controller)
{
    this->isBootstrapConfigured_ = isBootstrapConfigured;
    this->clusterResource_ = new ClusterResource(clusterId);
    this->nodes_ = nodes;

    std::map<int, Node*> tmpNodesById;
    for (auto iter : nodes)
        tmpNodesById[iter->id()] = iter;
    this->nodesById_ = tmpNodesById;

    std::map<TopicPartition*, PartitionInfo*> tmpPartitionsByTopicPartition;
    std::map<std::string, std::list<PartitionInfo*>> tmpPartitionsByTopic;
    std::map<std::string, std::list<PartitionInfo*>> tmpAvailablePartitionsByTopic;
    std::map<int, std::list<PartitionInfo*>> tmpPartitionsByNode;
    for (PartitionInfo *p : partitions)
    {
        tmpPartitionsByTopicPartition[new TopicPartition(p->topic(), p->partition())] = p;

        tmpPartitionsByTopic[p->topic()].push_back(p);
        if (p->leader() != NULL)
        {
            tmpAvailablePartitionsByTopic[p->topic()].push_back(p);
            tmpPartitionsByNode[p->leader()->id()].push_back(p);
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
	return new Cluster(NULL, std::list<Node*>(), std::list<PartitionInfo*>(), std::set<std::string>(),
		std::set<std::string>(), NULL);
}

Cluster* Cluster::bootstrap(std::list<InetSocketAddress> addresses)
{
	std::list<Node*> nodes;
	int nodeId = -1;
	for (InetSocketAddress address : addresses)
		nodes.push_back(new Node(nodeId--, address.getHostString(), address.getPort()));
	return new Cluster(NULL, true, nodes, std::list<PartitionInfo*>(),
		std::set<std::string>(), std::set<std::string>(), std::set<std::string>(), NULL);
}

Cluster* Cluster::withPartitions(std::map<TopicPartition*, PartitionInfo*> partitions)
{
	std::map<TopicPartition*, PartitionInfo*> combinedPartitions;
	combinedPartitions.swap(partitions);
	return new Cluster(clusterResource_->clusterId().c_str(), this->nodes_, Utils::values(combinedPartitions),
		this->unauthorizedTopics_, this->invalidTopics_,
		this->internalTopics_, this->controller_);
}

Node* Cluster::leaderFor(TopicPartition *topicPartition)
{
	PartitionInfo *info = partitionsByTopicPartition_[topicPartition];
	if (info == NULL)
		return NULL;
	else
		return info->leader();
}

PartitionInfo* Cluster::partition(TopicPartition *topicPartition)
{
	return partitionsByTopicPartition_[topicPartition];
}

std::list<PartitionInfo*> Cluster::partitionsForTopic(const char *topic)
{
	return partitionsByTopic_[topic];
}

Integer* Cluster::partitionCountForTopic(const char *topic)
{
	std::list<PartitionInfo*> partitions = this->partitionsByTopic_[topic];
	return partitions.empty() ? NULL : new Integer(partitions.size());
}

std::list<PartitionInfo*> Cluster::availablePartitionsForTopic(const char *topic)
{
	return availablePartitionsByTopic_[topic];
}

std::list<PartitionInfo*> Cluster::partitionsForNode(int nodeId)
{
	return partitionsByNode_[nodeId];
}

std::set<std::string> Cluster::topics()
{
	std::set<std::string> t;
	for (std::map<std::string, std::list<PartitionInfo*>>::iterator iter = partitionsByTopic_.begin(); iter != partitionsByTopic_.end(); iter++)
	{
		t.insert(iter->first);
	}
	return t;
}

std::string Cluster::toString()
{
	return "Cluster(id = " + clusterResource_->clusterId() + ", nodes = " + Utils::join(this->nodes_, ",") +
		", partitions = " + Utils::join(Utils::values(this->partitionsByTopicPartition_), ",") + ", controller = " + controller_->toString() + ")";
}