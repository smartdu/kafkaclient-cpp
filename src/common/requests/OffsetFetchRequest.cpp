#include "OffsetFetchRequest.h"
#include "Field.h"
#include "Schema.h"
#include "CommonFields.h"
#include "Type.h"
#include "Struct.h"
#include "ApiKeys.h"
#include "AbstractResponse.h"
#include "IllegalArgumentException.h"
#include "Errors.h"
#include "ObjectArray.h"
#include "OffsetFetchResponse.h"
#include "String0.h"
#include "Integer.h"
#include "Arrays.h"
#include "CollectionUtils.h"

ComplexArray* OffsetFetchRequest::TOPICS = new ComplexArray("topics",
    "Topics to fetch offsets. If the topic array is null fetch offsets for all topics.");

ComplexArray* OffsetFetchRequest::PARTITIONS = new ComplexArray("partitions",
    "Partitions to fetch offsets.");

Field* OffsetFetchRequest::PARTITIONS_V0 = PARTITIONS->withFields(1,
    CommonFields::PARTITION_ID->clone());

Field* OffsetFetchRequest::TOPICS_V0 = TOPICS->withFields("Topics to fetch offsets.", 2,
    CommonFields::TOPIC_NAME->clone(),
    PARTITIONS_V0->clone());

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V0 = new Schema(2,
    CommonFields::GROUP_ID->clone(),
    TOPICS_V0->clone());

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V1 = OFFSET_FETCH_REQUEST_V0->clone();

Field* OffsetFetchRequest::TOPICS_V2 = TOPICS->nullableWithFields(2,
    CommonFields::TOPIC_NAME->clone(),
    PARTITIONS_V0->clone());

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V2 = new Schema(2,
    CommonFields::GROUP_ID->clone(),
    TOPICS_V2->clone());

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V3 = OFFSET_FETCH_REQUEST_V2->clone();

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V4 = OFFSET_FETCH_REQUEST_V3->clone();

Schema* OffsetFetchRequest::OFFSET_FETCH_REQUEST_V5 = OFFSET_FETCH_REQUEST_V4->clone();

Schema** OffsetFetchRequest::schemaVersions()
{
    static Schema* schemas[] = { OFFSET_FETCH_REQUEST_V0, OFFSET_FETCH_REQUEST_V1, OFFSET_FETCH_REQUEST_V2,
        OFFSET_FETCH_REQUEST_V3, OFFSET_FETCH_REQUEST_V4, OFFSET_FETCH_REQUEST_V5, NULL };
    return schemas;
}

OffsetFetchRequest* OffsetFetchRequest::forAllPartitions(const char *groupId)
{
    return new OffsetFetchRequest(groupId, std::list<TopicPartition*>(), 2);
}

OffsetFetchResponse* OffsetFetchRequest::getErrorResponse(Errors *error)
{
    return getErrorResponse(AbstractResponse::DEFAULT_THROTTLE_TIME, error);
}

OffsetFetchResponse* OffsetFetchRequest::getErrorResponse(int throttleTimeMs, Errors *error)
{
    short versionId = version();

    std::map<TopicPartition*, PartitionData*> responsePartitions;
    if (versionId < 2)
    {
        PartitionData *partitionError = new PartitionData(
            OffsetFetchResponse::INVALID_OFFSET,
            NULL,
            OffsetFetchResponse::NO_METADATA,
            error);

        for (auto iter : this->partitions_)
            responsePartitions[iter] = partitionError;
    }

    switch (versionId)
    {
    case 0:
    case 1:
    case 2:
        return new OffsetFetchResponse(error, responsePartitions);
    case 3:
    case 4:
    case 5:
        return new OffsetFetchResponse(throttleTimeMs, error, responsePartitions);
    default:
        throw IllegalArgumentException("Version " + std::to_string(versionId) + " is not valid. Valid versions for OffsetFetchRequest are 0 to " + std::to_string(ApiKeys::OFFSET_FETCH()->latestVersion()));
    }
}

OffsetFetchResponse* OffsetFetchRequest::getErrorResponse(int throttleTimeMs, ApiException *e)
{
    return getErrorResponse(throttleTimeMs, Errors::forException(e));
}

OffsetFetchRequest* OffsetFetchRequest::parse(ByteBuffer *buffer, short version)
{
    return new OffsetFetchRequest(ApiKeys::OFFSET_FETCH()->parseRequest(version, buffer), version);
}

Struct* OffsetFetchRequest::toStruct()
{
    Struct *s = new Struct(ApiKeys::OFFSET_FETCH()->requestSchema(version()));
    s->set(CommonFields::GROUP_ID, groupId_.c_str());
    if (!partitions_.empty())
    {
        std::map<std::string, std::list<int>> topicsData = CollectionUtils::groupPartitionsByTopic(partitions_);

        std::list<Struct*> topicArray;
        for (auto &iter : topicsData) 
        {
            Struct *topicData = s->instance(TOPICS);
            topicData->set(CommonFields::TOPIC_NAME, iter.first.c_str());
            std::list<Struct*> partitionArray;
            for (auto iter2 : iter.second)
            {
                Struct *partitionData = topicData->instance(PARTITIONS);
                partitionData->set(CommonFields::PARTITION_ID, iter2);
                partitionArray.push_back(partitionData);
            }
            topicData->set(PARTITIONS, Arrays::toArray(partitionArray));
            topicArray.push_back(topicData);
        }
        s->set(TOPICS, Arrays::toArray(topicArray));
    }
    else
        s->set(TOPICS, NULL);

    return s;
}

OffsetFetchRequest::OffsetFetchRequest(const char *groupId, std::list<TopicPartition*> partitions, short version)
    : AbstractRequest(ApiKeys::OFFSET_FETCH(), version)
{
    this->groupId_ = groupId;
    this->partitions_ = partitions;
}

OffsetFetchRequest::OffsetFetchRequest(Struct *s, short version)
{
    ObjectArray *topicArray = s->get(TOPICS);
    if (topicArray != NULL)
    {
        for (int i = 0; i < *topicArray; i++)
        {
            Struct *topicResponse = (Struct*)(*topicArray)[i];
            String *topic = topicResponse->get(CommonFields::TOPIC_NAME);

            ObjectArray *oa = topicResponse->get(PARTITIONS);
            for (int i = 0; i < *oa; i ++)
            {
                Struct *partitionResponse = (Struct*)(*oa)[i];
                int partition = *partitionResponse->get(CommonFields::PARTITION_ID);
                partitions_.push_back(new TopicPartition(*topic, partition));
            }
        }
    }

    groupId_ = (const char*)s->get(CommonFields::GROUP_ID);
}

void OffsetFetchRequest::destroy()
{
    Field::destroy(PARTITIONS_V0);
    Field::destroy(TOPICS_V0);
    Schema::destroy(OFFSET_FETCH_REQUEST_V0);
    Schema::destroy(OFFSET_FETCH_REQUEST_V1);
    Field::destroy(TOPICS_V2);
    Schema::destroy(OFFSET_FETCH_REQUEST_V2);
    Schema::destroy(OFFSET_FETCH_REQUEST_V3);
    Schema::destroy(OFFSET_FETCH_REQUEST_V4);
    Schema::destroy(OFFSET_FETCH_REQUEST_V5);
}
