#ifndef __KFK_OFFSETFETCHREQUEST_H__
#define __KFK_OFFSETFETCHREQUEST_H__

#pragma once
#include "AbstractRequest.h"
#include "TopicPartition.h"
#include <list>
class Schema;
class ComplexArray;
class Field;
class Errors;
class OffsetFetchResponse;
class ApiException;

class OffsetFetchRequest
    : public AbstractRequest
{
public:
    OffsetFetchRequest(Struct *s, short version);

    OffsetFetchResponse* getErrorResponse(Errors *error);

    OffsetFetchResponse* getErrorResponse(int throttleTimeMs, Errors *error);

    OffsetFetchResponse* getErrorResponse(int throttleTimeMs, ApiException *e);

    const char* groupId()
    {
        return groupId_.c_str();
    }

    std::list<TopicPartition*> partitions()
    {
        return partitions_;
    }

    static OffsetFetchRequest* parse(ByteBuffer *buffer, short version);

    bool isAllPartitions()
    {
        return partitions_.empty();
    }

    static Schema** schemaVersions();

    static OffsetFetchRequest* forAllPartitions(const char *groupId);

    static void destroy();

protected:
    virtual Struct* toStruct();

private:
    OffsetFetchRequest(const char *groupId, std::list<TopicPartition*> partitions, short version);

private:
    static ComplexArray *TOPICS;
    static ComplexArray *PARTITIONS;
    static Field *PARTITIONS_V0;
    static Field *TOPICS_V0;
    static Schema *OFFSET_FETCH_REQUEST_V0;
    static Schema *OFFSET_FETCH_REQUEST_V1;
    static Field *TOPICS_V2;
    static Schema *OFFSET_FETCH_REQUEST_V2;
    static Schema *OFFSET_FETCH_REQUEST_V3;
    static Schema *OFFSET_FETCH_REQUEST_V4;
    static Schema *OFFSET_FETCH_REQUEST_V5;

    std::string groupId_;
    std::list<TopicPartition*> partitions_;
};

#endif // __KFK_OFFSETFETCHREQUEST_H__
