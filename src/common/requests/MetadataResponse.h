#ifndef __KFK_METADATARESPONSE_H__
#define __KFK_METADATARESPONSE_H__

#pragma once
#include "AbstractResponse.h"
#include "Field.h"
#include "Node.h"
#include "String0.h"
#include <list>
#include <map>
#include <set>
class Schema;
class Struct;
class ByteBuffer;
class ObjectArray;
class Integer;
class Cluster;
class PartitionInfo;

class PartitionMetadata
{
public:
	PartitionMetadata(Errors *error, int partition, Node *leader, Integer *leaderEpoch, std::list<Node*> replicas, std::list<Node*> isr, std::list<Node*> offlineReplicas);

	Errors* error()
	{
		return error_;
	}

	int partition()
	{
		return partition_;
	}

	int leaderId()
	{
		return leader_ == NULL ? -1 : leader_->id();
	}

	Integer* leaderEpoch()
	{
		return leaderEpoch_;
	}

	Node* leader()
	{
		return leader_;
	}

	std::list<Node*> replicas()
	{
		return replicas_;
	}

	std::list<Node*> isr()
	{
		return isr_;
	}

	std::list<Node*> offlineReplicas()
	{
		return offlineReplicas_;
	}

	virtual std::string toString();

private:
	Errors *error_;
	int partition_;
	Node *leader_;
	Integer *leaderEpoch_;
	std::list<Node*> replicas_;
	std::list<Node*> isr_;
	std::list<Node*> offlineReplicas_;
};

class TopicMetadata
{
public:
	TopicMetadata(Errors *error, const char *topic, bool isInternal, std::list<PartitionMetadata*> partitionMetadata);

	Errors* error()
	{
		return error_;
	}

	std::string topic()
	{
		return topic_;
	}

	bool isInternal()
	{
		return isInternal_;
	}

	std::list<PartitionMetadata*> partitionMetadata()
	{
		return partitionMetadata_;
	}

	virtual std::string toString();

private:
	Errors *error_;
	std::string topic_;
	bool isInternal_;
	std::list<PartitionMetadata*> partitionMetadata_;
};

class MetadataResponse
	: public AbstractResponse
{
public:
	static const int NO_CONTROLLER_ID = -1;

	static Schema** schemaVersions();

	MetadataResponse(std::list<Node*> brokers, const char *clusterId, int controllerId, std::list<TopicMetadata*> topicMetadata);
	MetadataResponse(int throttleTimeMs, std::list<Node*> brokers, const char *clusterId, int controllerId, std::list<TopicMetadata*> topicMetadata);
	MetadataResponse(Struct *s);

	int throttleTimeMs()
	{
		return throttleTimeMs_;
	}

	std::map<std::string, Errors*> errors();

	virtual std::map<Errors*, int> errorCounts();

	std::set<std::string> topicsByError(Errors *error);

	std::set<std::string> unavailableTopics();

	Cluster* cluster();

	static PartitionInfo* partitionMetaToInfo(const char *topic, PartitionMetadata *partitionMetadata);

	std::list<Node*> brokers()
	{
		return this->brokers_;
	}

	std::list<TopicMetadata*> topicMetadata()
	{
		return this->topicMetadata_;
	}

	Node* controller()
	{
		return controller_;
	}

	const char* clusterId()
	{
		return *this->clusterId_;
	}

	static MetadataResponse* parse(ByteBuffer *buffer, short version);

	virtual bool shouldClientThrottle(short version)
	{
		return version >= 6;
	}

protected:
	virtual Struct* toStruct(short version);

private:
	std::list<Node*> convertToNodes(std::map<int, Node*> brokers, ObjectArray *brokerIds);

	Node* getControllerNode(int controllerId, std::list<Node*> brokers);

private:
	static ComplexArray *BROKERS;
	static ComplexArray *TOPIC_METADATA;
	static NullableStr *CLUSTER_ID;
	static Int32 *CONTROLLER_ID;
	static Int32 *NODE_ID;
	static Str *HOST;
	static Int32 *PORT;
	static NullableStr *RACK;
	static ComplexArray *PARTITION_METADATA;
	static Bool *IS_INTERNAL;
	static Int32 *LEADER;
	static Array *REPLICAS;
	static Array *ISR;
	static Array *OFFLINE_REPLICAS;
	static Field *METADATA_BROKER_V0;
	static Field *PARTITION_METADATA_V0;
	static Field *TOPIC_METADATA_V0;
	static Schema *METADATA_RESPONSE_V0;
	static Field *METADATA_BROKER_V1;
	static Field *TOPIC_METADATA_V1;
	static Schema *METADATA_RESPONSE_V1;
	static Schema *METADATA_RESPONSE_V2;
	static Schema *METADATA_RESPONSE_V3;
	static Schema *METADATA_RESPONSE_V4;
	static Field *PARTITION_METADATA_V5;
	static Field *TOPIC_METADATA_V5;
	static Schema *METADATA_RESPONSE_V5;
	static Schema *METADATA_RESPONSE_V6;
	static Field *PARTITION_METADATA_V7;
	static Field *TOPIC_METADATA_V7;
	static Schema *METADATA_RESPONSE_V7;

	int throttleTimeMs_;
	std::list<Node*> brokers_;
	Node *controller_;
	std::list<TopicMetadata*> topicMetadata_;
	String *clusterId_;
};

#endif // !__KFK_METADATARESPONSE_H__
