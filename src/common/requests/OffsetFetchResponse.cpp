#include "OffsetFetchResponse.h"
#include "Field.h"
#include "CommonFields.h"
#include "Schema.h"
#include "Integer.h"
#include "Struct.h"
#include "Short.h"
#include "Long.h"
#include "TopicPartition.h"
#include "String0.h"
#include "RequestUtils.h"
#include "Errors.h"
#include "ByteBuffer.h"
#include "ObjectArray.h"
#include "ApiKeys.h"
#include "Arrays.h"
#include "CollectionUtils.h"
#include <algorithm>

ComplexArray* OffsetFetchResponse::TOPICS = new ComplexArray("responses",
    "Responses by topic for fetched offsets");

ComplexArray* OffsetFetchResponse::PARTITIONS = new ComplexArray("partition_responses",
    "Responses by partition for fetched offsets");

Field* OffsetFetchResponse::PARTITIONS_V0 = PARTITIONS->withFields(4,
    CommonFields::PARTITION_ID->clone(),
    CommonFields::COMMITTED_OFFSET->clone(),
    CommonFields::COMMITTED_METADATA->clone(),
    CommonFields::ERROR_CODE->clone());

Field* OffsetFetchResponse::TOPICS_V0 = TOPICS->withFields(2,
    CommonFields::TOPIC_NAME->clone(),
    PARTITIONS_V0->clone());

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V0 = new Schema(1,
    TOPICS_V0->clone());

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V1 = OFFSET_FETCH_RESPONSE_V0->clone();

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V2 = new Schema(2,
    TOPICS_V0->clone(),
    CommonFields::ERROR_CODE->clone());

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V3 = new Schema(3,
    CommonFields::THROTTLE_TIME_MS->clone(),
    TOPICS_V0->clone(),
    CommonFields::ERROR_CODE->clone());

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V4 = OFFSET_FETCH_RESPONSE_V3->clone();

Field* OffsetFetchResponse::PARTITIONS_V5 = PARTITIONS->withFields(5,
    CommonFields::PARTITION_ID->clone(),
    CommonFields::COMMITTED_OFFSET->clone(),
    CommonFields::COMMITTED_LEADER_EPOCH->clone(),
    CommonFields::COMMITTED_METADATA->clone(),
    CommonFields::ERROR_CODE->clone());

Field* OffsetFetchResponse::TOPICS_V5 = TOPICS->withFields(2,
    CommonFields::TOPIC_NAME->clone(),
    PARTITIONS_V5->clone());

Schema* OffsetFetchResponse::OFFSET_FETCH_RESPONSE_V5 = new Schema(3,
    CommonFields::THROTTLE_TIME_MS->clone(),
    TOPICS_V5->clone(),
    CommonFields::ERROR_CODE->clone());

const char* OffsetFetchResponse::NO_METADATA = "";
PartitionData* OffsetFetchResponse::UNKNOWN_PARTITION = new PartitionData(INVALID_OFFSET, NULL, NO_METADATA, Errors::UNKNOWN_TOPIC_OR_PARTITION);
PartitionData* OffsetFetchResponse::UNAUTHORIZED_PARTITION = new PartitionData(INVALID_OFFSET, NULL, NO_METADATA, Errors::TOPIC_AUTHORIZATION_FAILED);
std::list<Errors*> OffsetFetchResponse::PARTITION_ERRORS = CollectionUtils::singletonList(Errors::UNKNOWN_TOPIC_OR_PARTITION);

Schema** OffsetFetchResponse::schemaVersions()
{
    static Schema* schemas[] = { OFFSET_FETCH_RESPONSE_V0, OFFSET_FETCH_RESPONSE_V1, OFFSET_FETCH_RESPONSE_V2,
        OFFSET_FETCH_RESPONSE_V3, OFFSET_FETCH_RESPONSE_V4, OFFSET_FETCH_RESPONSE_V5, NULL };
    return schemas;
}

OffsetFetchResponse::OffsetFetchResponse(Errors *error, std::map<TopicPartition*, PartitionData*> responseData)
{
    init(DEFAULT_THROTTLE_TIME, error, responseData);
}

OffsetFetchResponse::OffsetFetchResponse(int throttleTimeMs, Errors *error, std::map<TopicPartition*, PartitionData*> responseData)
{
    init(throttleTimeMs, error, responseData);
}

OffsetFetchResponse::OffsetFetchResponse(Struct *s)
{
    this->throttleTimeMs_ = *s->getOrElse(CommonFields::THROTTLE_TIME_MS, DEFAULT_THROTTLE_TIME);
    Errors *topLevelError = Errors::NONE;
    ObjectArray *oa = s->get(TOPICS);
    for (int i = 0; i < *oa; i ++)
    {
        Struct *topicResponse = (Struct*)(*oa)[i];
        String *topic = topicResponse->get(CommonFields::TOPIC_NAME);
        ObjectArray *oa1 = topicResponse->get(TOPICS);
        for (int j = 0; j < *oa; j++)
        {
            Struct *partitionResponse = (Struct*)(*oa1)[j];
            int partition = *partitionResponse->get(CommonFields::PARTITION_ID);
            long long offset = *partitionResponse->get(CommonFields::COMMITTED_OFFSET);
            String *metadata = partitionResponse->get(CommonFields::COMMITTED_METADATA);
            Integer *leaderEpochOpt = RequestUtils::getLeaderEpoch(partitionResponse, CommonFields::COMMITTED_LEADER_EPOCH);

            Errors *error = Errors::forCode(*partitionResponse->get(CommonFields::ERROR_CODE));
            std::find(PARTITION_ERRORS.begin(), PARTITION_ERRORS.end(), error);
            if (error != Errors::NONE && std::find(PARTITION_ERRORS.begin(), PARTITION_ERRORS.end(), error) == PARTITION_ERRORS.end())
                topLevelError = error;

            PartitionData *partitionData = new PartitionData(offset, leaderEpochOpt, *metadata, error);
            this->responseData_[new TopicPartition(*topic, partition)] = partitionData;
        }
    }

    this->error_ = s->hasField(CommonFields::ERROR_CODE) ? Errors::forCode(*s->get(CommonFields::ERROR_CODE)) : topLevelError;
}

void OffsetFetchResponse::init(int throttleTimeMs, Errors *error, std::map<TopicPartition*, PartitionData*> responseData)
{
    this->throttleTimeMs_ = throttleTimeMs;
    this->error_ = error;
    this->responseData_ = responseData_;
}

void OffsetFetchResponse::maybeThrowFirstPartitionError()
{
    for (auto &iter : this->responseData_)
    {
        if (iter.second->hasError())
            throw iter.second->error->exception();
    }
}

OffsetFetchResponse* OffsetFetchResponse::parse(ByteBuffer *buffer, short version)
{
    return new OffsetFetchResponse(ApiKeys::OFFSET_FETCH()->parseResponse(version, buffer));
}

Struct* OffsetFetchResponse::toStruct(short version)
{
    Struct *s = new Struct(ApiKeys::OFFSET_FETCH()->responseSchema(version));
    s->setIfExists(CommonFields::THROTTLE_TIME_MS, new Integer(throttleTimeMs_));

    std::map<std::string, std::map<int, PartitionData*>> topicsData = CollectionUtils::groupPartitionDataByTopic(responseData_);
    std::list<Struct*> topicArray;
    for (auto &iter : topicsData)
    {
        Struct *topicData = s->instance(TOPICS);
        topicData->set(CommonFields::TOPIC_NAME, iter.first.c_str());
        std::list<Struct*> partitionArray;
        for (auto &iter2 : iter.second)
        {
            PartitionData *fetchPartitionData = iter2.second;
            Struct *partitionData = topicData->instance(PARTITIONS);
            partitionData->set(CommonFields::PARTITION_ID, iter2.first);
            partitionData->set(CommonFields::COMMITTED_OFFSET, fetchPartitionData->offset);
            RequestUtils::setLeaderEpochIfExists(partitionData, CommonFields::COMMITTED_LEADER_EPOCH, fetchPartitionData->leaderEpoch);
            partitionData->set(CommonFields::COMMITTED_METADATA, fetchPartitionData->metadata.c_str());
            partitionData->set(CommonFields::ERROR_CODE, fetchPartitionData->error->code());
            partitionArray.push_back(partitionData);
        }
        topicData->set(PARTITIONS, Arrays::toArray(partitionArray));
        topicArray.push_back(topicData);
    }
    s->set(TOPICS, Arrays::toArray(topicArray));

    if (version > 1)
        s->set(CommonFields::ERROR_CODE, this->error_->code());

    return s;
}

void OffsetFetchResponse::destroy()
{
    Field::destroy(PARTITIONS_V0);
    Field::destroy(TOPICS_V0);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V0);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V1);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V2);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V3);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V4);
    Field::destroy(PARTITIONS_V5);
    Field::destroy(TOPICS_V5);
    Schema::destroy(OFFSET_FETCH_RESPONSE_V5);

    DELETE_OBJ(UNKNOWN_PARTITION);
    DELETE_OBJ(UNAUTHORIZED_PARTITION);
}