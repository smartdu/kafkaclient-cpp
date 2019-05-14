#ifndef __KFK_OFFSETFETCHRESPONSE_H__
#define __KFK_OFFSETFETCHRESPONSE_H__

#pragma once
#include "AbstractResponse.h"
#include "Errors.h"
#include <string>
#include <list>
class ComplexArray;
class Field;
class Schema;
class TopicPartition;
class Integer;

class PartitionData
{
public:
    long long offset;
    std::string metadata;
    Errors *error;
    Integer *leaderEpoch;

    PartitionData(long long offset, Integer *leaderEpoch, const char *metadata, Errors *error)
    {
        this->offset = offset;
        this->leaderEpoch = leaderEpoch;
        this->metadata = metadata;
        this->error = error;
    }

    bool hasError()
    {
        return error != Errors::NONE;
    }
};

class OffsetFetchResponse
    : public AbstractResponse
{
public:
    static const long INVALID_OFFSET = -1L;
    static const const char *NO_METADATA;
    static PartitionData *UNKNOWN_PARTITION;
    static PartitionData *UNAUTHORIZED_PARTITION;

    static Schema** schemaVersions();

    OffsetFetchResponse(Errors *error, std::map<TopicPartition*, PartitionData*> responseData);
    OffsetFetchResponse(int throttleTimeMs, Errors *error, std::map<TopicPartition*, PartitionData*> responseData);
    OffsetFetchResponse(Struct *s);

    void maybeThrowFirstPartitionError();

    int throttleTimeMs()
    {
        return throttleTimeMs_;
    }

    bool hasError()
    {
        return this->error_ != Errors::NONE;
    }

    Errors* error()
    {
        return this->error_;
    }

    std::map<Errors*, int> errorCounts()
    {
        return AbstractResponse::errorCounts(error_);
    }

    std::map<TopicPartition*, PartitionData*> responseData()
    {
        return responseData_;
    }

    static OffsetFetchResponse* parse(ByteBuffer *buffer, short version);

    bool shouldClientThrottle(short version)
    {
        return version >= 4;
    }

    static void destroy();

protected:
    Struct* toStruct(short version);

    void init(int throttleTimeMs, Errors *error, std::map<TopicPartition*, PartitionData*> responseData);

private:
    static ComplexArray *TOPICS;
    static ComplexArray *PARTITIONS;
    static Field *PARTITIONS_V0;
    static Field *TOPICS_V0;
    static Schema *OFFSET_FETCH_RESPONSE_V0;
    static Schema *OFFSET_FETCH_RESPONSE_V1;
    static Schema *OFFSET_FETCH_RESPONSE_V2;
    static Schema *OFFSET_FETCH_RESPONSE_V3;
    static Schema *OFFSET_FETCH_RESPONSE_V4;
    static Field *PARTITIONS_V5;
    static Field *TOPICS_V5;
    static Schema *OFFSET_FETCH_RESPONSE_V5;

    static std::list<Errors*> PARTITION_ERRORS;

    std::map<TopicPartition*, PartitionData*> responseData_;
    Errors *error_;
    int throttleTimeMs_;
};

#endif // !__KFK_OFFSETFETCHRESPONSE_H__
