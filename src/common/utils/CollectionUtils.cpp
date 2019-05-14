#include "CollectionUtils.h"

std::map<std::string, std::list<int>> CollectionUtils::groupPartitionsByTopic(std::list<TopicPartition*> &partitions)
{
    std::map<std::string, std::list<int>> partitionsByTopic;
    for (auto iter : partitions)
    {
        const char *topic = iter->topic();
        std::list<int> &topicData = partitionsByTopic[topic];
        topicData.push_back(iter->partition());
    }
    return partitionsByTopic;
}

std::list<Errors*> CollectionUtils::singletonList(Errors* t)
{
    std::list<Errors*> l;
    l.push_back(t);
    return l;
}