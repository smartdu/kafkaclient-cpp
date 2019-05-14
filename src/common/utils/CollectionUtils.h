#ifndef __KFK_COLLECTIONUTILS_H__
#define __KFK_COLLECTIONUTILS_H__

#pragma once
#include <string>
#include <map>
#include <list>
#include "TopicPartition.h"
class Errors;

class CollectionUtils
{
public:
    template<class T>
    static std::map<std::string, std::map<int, T>> groupPartitionDataByTopic(std::map<TopicPartition*, T> data)
    {
        std::map<std::string, std::map<int, T>> dataByTopic;
        for (auto &iter : data)
        {
            const char *topic = iter.first->topic();
            int partition = iter.first->partition();
            std::map<int, T> &v = dataByTopic[topic];
            v[partition] = iter.second;
        }
        return dataByTopic;
    }

    static std::map<std::string, std::list<int>> groupPartitionsByTopic(std::list<TopicPartition*> &partitions);

    static std::list<Errors*> singletonList(Errors *t);
};

#endif // !__KFK_COLLECTIONUTILS_H__
