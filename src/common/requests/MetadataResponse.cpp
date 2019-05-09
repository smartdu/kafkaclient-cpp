#include "MetadataResponse.h"
#include "Errors.h"
#include "Integer.h"
#include "Utils.h"
#include "CommonFields.h"
#include "Struct.h"
#include "Schema.h"
#include "Field.h"
#include "ObjectArray.h"
#include "PartitionInfo.h"
#include <set>

ComplexArray* MetadataResponse::BROKERS = new ComplexArray("brokers",
	"Host and port information for all brokers.");
ComplexArray* MetadataResponse::TOPIC_METADATA = new ComplexArray("topic_metadata",
	"Metadata for requested topics");

NullableStr* MetadataResponse::CLUSTER_ID = new NullableStr("cluster_id",
	"The cluster id that this broker belongs to.");
Int32* MetadataResponse::CONTROLLER_ID = new Int32("controller_id",
	"The broker id of the controller broker.");

Int32* MetadataResponse::NODE_ID = new Int32("node_id", "The broker id.");
Str* MetadataResponse::HOST = new Str("host", "The hostname of the broker.");
Int32* MetadataResponse::PORT = new Int32("port", "The port on which the broker accepts requests.");
NullableStr* MetadataResponse::RACK = new NullableStr("rack", "The rack of the broker.");

ComplexArray* MetadataResponse::PARTITION_METADATA = new ComplexArray("partition_metadata",
	"Metadata for each partition of the topic.");
Bool* MetadataResponse::IS_INTERNAL = new Bool("is_internal",
	"Indicates if the topic is considered a Kafka internal topic");

Int32* MetadataResponse::LEADER = new Int32("leader",
	"The id of the broker acting as leader for this partition.");
Array* MetadataResponse::REPLICAS = new Array("replicas", Type::INT32(),
	"The set of all nodes that host this partition.");
Array* MetadataResponse::ISR = new Array("isr", Type::INT32(),
	"The set of nodes that are in sync with the leader for this partition.");
Array* MetadataResponse::OFFLINE_REPLICAS = new Array("offline_replicas", Type::INT32(),
	"The set of offline replicas of this partition.");

Field* MetadataResponse::METADATA_BROKER_V0 = BROKERS->withFields(3,
	NODE_ID,
	HOST,
	PORT);

Field* MetadataResponse::PARTITION_METADATA_V0 = PARTITION_METADATA->withFields(5,
	CommonFields::ERROR_CODE,
	CommonFields::PARTITION_ID,
	LEADER,
	REPLICAS,
	ISR);

Field* MetadataResponse::TOPIC_METADATA_V0 = TOPIC_METADATA->withFields(3,
	CommonFields::ERROR_CODE,
	CommonFields::TOPIC_NAME,
	PARTITION_METADATA_V0);

Schema* MetadataResponse::METADATA_RESPONSE_V0 = new Schema(2,
	METADATA_BROKER_V0,
	TOPIC_METADATA_V0);

Field* MetadataResponse::METADATA_BROKER_V1 = BROKERS->withFields(4,
	NODE_ID,
	HOST,
	PORT,
	RACK);

Field* MetadataResponse::TOPIC_METADATA_V1 = TOPIC_METADATA->withFields(4,
	CommonFields::ERROR_CODE,
	CommonFields::TOPIC_NAME,
	IS_INTERNAL,
	PARTITION_METADATA_V0);

Schema* MetadataResponse::METADATA_RESPONSE_V1 = new Schema(3,
	METADATA_BROKER_V1,
	CONTROLLER_ID,
	TOPIC_METADATA_V1);

Schema* MetadataResponse::METADATA_RESPONSE_V2 = new Schema(4,
	METADATA_BROKER_V1,
	CLUSTER_ID,
	CONTROLLER_ID,
	TOPIC_METADATA_V1);

Schema* MetadataResponse::METADATA_RESPONSE_V3 = new Schema(5,
	CommonFields::THROTTLE_TIME_MS,
	METADATA_BROKER_V1,
	CLUSTER_ID,
	CONTROLLER_ID,
	TOPIC_METADATA_V1);

Schema* MetadataResponse::METADATA_RESPONSE_V4 = METADATA_RESPONSE_V3;

Field* MetadataResponse::PARTITION_METADATA_V5 = PARTITION_METADATA->withFields(6,
	CommonFields::ERROR_CODE,
	CommonFields::PARTITION_ID,
	LEADER,
	REPLICAS,
	ISR,
	OFFLINE_REPLICAS);

Field* MetadataResponse::TOPIC_METADATA_V5 = TOPIC_METADATA->withFields(4,
	CommonFields::ERROR_CODE,
	CommonFields::TOPIC_NAME,
	IS_INTERNAL,
	PARTITION_METADATA_V5);

Schema* MetadataResponse::METADATA_RESPONSE_V5 = new Schema(5,
	CommonFields::THROTTLE_TIME_MS,
	METADATA_BROKER_V1,
	CLUSTER_ID,
	CONTROLLER_ID,
	TOPIC_METADATA_V5);

Schema* MetadataResponse::METADATA_RESPONSE_V6 = METADATA_RESPONSE_V5;

Field* MetadataResponse::PARTITION_METADATA_V7 = PARTITION_METADATA->withFields(7,
	CommonFields::ERROR_CODE,
	CommonFields::PARTITION_ID,
	LEADER,
	CommonFields::LEADER_EPOCH,
	REPLICAS,
	ISR,
	OFFLINE_REPLICAS);

Field* MetadataResponse::TOPIC_METADATA_V7 = TOPIC_METADATA->withFields(4,
	CommonFields::ERROR_CODE,
	CommonFields::TOPIC_NAME,
	IS_INTERNAL,
	PARTITION_METADATA_V7);

Schema* MetadataResponse::METADATA_RESPONSE_V7 = new Schema(5,
	CommonFields::THROTTLE_TIME_MS,
	METADATA_BROKER_V1,
	CLUSTER_ID,
	CONTROLLER_ID,
	TOPIC_METADATA_V7);

PartitionMetadata::PartitionMetadata(Errors *error, int partition, Node *leader, Integer *leaderEpoch, std::list<Node> replicas, std::list<Node> isr, std::list<Node> offlineReplicas)
{
	this->error_ = error;
	this->partition_ = partition;
	this->leader_ = leader;
	this->leaderEpoch_ = leaderEpoch;
	this->replicas_ = replicas;
	this->isr_ = isr;
	this->offlineReplicas_ = offlineReplicas;
}

std::string PartitionMetadata::toString()
{
	return "(type=PartitionMetadata"
		", error=" + error_->toString() +
		", partition=" + std::to_string(partition_) +
		", leader=" + leader_->toString() +
		", leaderEpoch=" + std::to_string(*leaderEpoch_) +
		", replicas=" + Utils::join(replicas, ",") +
		", isr=" + Utils::join(isr, ",") +
		", offlineReplicas=" + Utils::join(offlineReplicas, ",") + ')';
}

TopicMetadata::TopicMetadata(Errors *error, const char *topic, bool isInternal, std::list<PartitionMetadata> partitionMetadata)
{
	this->error_ = error;
	this->topic_ = topic;
	this->isInternal_ = isInternal;
	this->partitionMetadata_ = partitionMetadata;
}

std::string TopicMetadata::toString() {
	return "(type=TopicMetadata"
		", error=" + error_->toString() +
		", topic=" + topic_ +
		", isInternal=" + std::to_string(isInternal_) +
		", partitionMetadata=" + partitionMetadata_ + ')';
}

Schema** MetadataResponse::schemaVersions()
{

}

MetadataResponse::MetadataResponse(std::list<Node> brokers, const char *clusterId, int controllerId, std::list<TopicMetadata> topicMetadata)
{
	new (this)MetadataResponse(DEFAULT_THROTTLE_TIME, brokers, clusterId, controllerId, topicMetadata);
}

MetadataResponse::MetadataResponse(int throttleTimeMs, std::list<Node> brokers, const char *clusterId, int controllerId, std::list<TopicMetadata> topicMetadata)
{
	this->throttleTimeMs_ = throttleTimeMs;
	this->brokers_ = brokers;
	this->controller_ = getControllerNode(controllerId, brokers);
	this->topicMetadata_ = topicMetadata;
	this->clusterId_ = clusterId;
}

MetadataResponse::MetadataResponse(Struct *s)
{
	this->throttleTimeMs_ = *s->getOrElse(CommonFields::THROTTLE_TIME_MS, DEFAULT_THROTTLE_TIME);
	std::map<int, Node> brokers;
	ObjectArray *brokerStructs = s->get(BROKERS);
	for (Object brokerStruct : brokerStructs) {
		Struct broker = (Struct)brokerStruct;
		int nodeId = broker.get(NODE_ID);
		String host = broker.get(HOST);
		int port = broker.get(PORT);
		// This field only exists in v1+
		// When we can't know if a rack exists in a v0 response we default to null
		String rack = broker.getOrElse(RACK, null);
		brokers.put(nodeId, new Node(nodeId, host, port, rack));
	}

	// This field only exists in v1+
	// When we can't know the controller id in a v0 response we default to NO_CONTROLLER_ID
	int controllerId = *s->getOrElse(CONTROLLER_ID, NO_CONTROLLER_ID);

	// This field only exists in v2+
	this->clusterId_ = s->getOrElse(CLUSTER_ID, NULL);

	std::list<TopicMetadata> topicMetadata;
	ObjectArray *topicInfos = s->get(TOPIC_METADATA);
	for (Object topicInfoObj : topicInfos) {
		Struct topicInfo = (Struct)topicInfoObj;
		Errors *topicError = Errors::forCode(topicInfo.get(CommonFields::ERROR_CODE));
		String topic = topicInfo.get(TOPIC_NAME);
		// This field only exists in v1+
		// When we can't know if a topic is internal or not in a v0 response we default to false
		boolean isInternal = topicInfo.getOrElse(IS_INTERNAL, false);
		std::list<PartitionMetadata> partitionMetadata;

		ObjectArray *partitionInfos = topicInfo->get(PARTITION_METADATA);
		for (Object partitionInfoObj : partitionInfos) {
			Struct partitionInfo = (Struct)partitionInfoObj;
			Errors partitionError = Errors.forCode(partitionInfo.get(CommonFields::ERROR_CODE));
			int partition = partitionInfo.get(PARTITION_ID);
			int leader = partitionInfo.get(LEADER);
			Optional<Integer> leaderEpoch = RequestUtils.getLeaderEpoch(partitionInfo, LEADER_EPOCH);
			Node leaderNode = leader == -1 ? null : brokers.get(leader);

			Object[] replicas = partitionInfo.get(REPLICAS);
			List<Node> replicaNodes = convertToNodes(brokers, replicas);

			Object[] isr = partitionInfo.get(ISR);
			List<Node> isrNodes = convertToNodes(brokers, isr);

			Object[] offlineReplicas = partitionInfo.getOrEmpty(OFFLINE_REPLICAS);
			List<Node> offlineNodes = convertToNodes(brokers, offlineReplicas);

			partitionMetadata.add(new PartitionMetadata(partitionError, partition, leaderNode, leaderEpoch,
				replicaNodes, isrNodes, offlineNodes));
		}

		topicMetadata.push_back(TopicMetadata(topicError, topic, isInternal, partitionMetadata));
	}

	this->brokers_ = brokers.values();
	this->controller = getControllerNode(controllerId, brokers.values());
	this->topicMetadata = topicMetadata;
}

std::map<std::string, Errors*> MetadataResponse::errors()
{

}

std::map<Errors*, int> MetadataResponse::errorCounts()
{

}

std::set<std::string> MetadataResponse::topicsByError(Errors *error)
{

}

std::set<std::string> MetadataResponse::unavailableTopics()
{

}

Cluster* MetadataResponse::cluster()
{
	std::set<std::string> internalTopics;
	std::list<PartitionInfo> partitions;
	for (auto iter : topicMetadata_)
	{
		TopicMetadata metadata = iter;
		if (metadata.error() == Errors::NONE)
		{
			if (metadata.isInternal)
				internalTopics.insert(metadata.topic);
			for (PartitionMetadata partitionMetadata : metadata.partitionMetadata)
			{
				partitions.push_back(partitionMetaToInfo(metadata.topic().c_str(), partitionMetadata));
			}
		}
	}
	return new Cluster(this->clusterId_, this->brokers, partitions, topicsByError(Errors::TOPIC_AUTHORIZATION_FAILED),
		topicsByError(Errors::INVALID_TOPIC_EXCEPTION), internalTopics, this->controller_);
}

PartitionInfo* MetadataResponse::partitionMetaToInfo(const char *topic, PartitionMetadata partitionMetadata)
{
	return new PartitionInfo(
		topic,
		partitionMetadata.partition(),
		partitionMetadata.leader(),
		partitionMetadata.replicas(),
		partitionMetadata.isr(),
		partitionMetadata.offlineReplicas());
}

MetadataResponse* MetadataResponse::parse(ByteBuffer *buffer, short version)
{
	return NULL;
}

Struct* MetadataResponse::toStruct(short version)
{
	return NULL;
}

std::list<Node> MetadataResponse::convertToNodes(std::map<int, Node> brokers, ObjectArray *brokerIds)
{
	std::list<Node> nodes;
	for (int i = 0; i < brokerIds->length; i++)
	{
		Object *brokerId = (*brokerIds)[i];
		int id = *(Integer*)brokerId;
		if (brokers.find(id) != brokers.end())
			nodes.push_back(brokers[id]);
		else
			nodes.push_back(Node(id, "", -1));
	}
	return nodes;
}

Node* MetadataResponse::getControllerNode(int controllerId, std::list<Node*> brokers)
{
	for (auto iter : brokers)
	{
		if (iter->id() == controllerId)
			return iter;
	}
	return NULL;
}

