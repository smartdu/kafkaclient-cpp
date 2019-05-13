#include "CommonFields.h"
#include "PatternType.h"

std::list<Field*> *_cf_values_ = new std::list<Field*>();
std::list<Type*> *_t_values_ = new std::list<Type*>();

Int32* CommonFields::THROTTLE_TIME_MS = new Int32("throttle_time_ms",
	"Duration in milliseconds for which the request was throttled due to quota violation (Zero if the "
	"request did not violate any quota)", 0, false);
Str* CommonFields::TOPIC_NAME = new Str("topic", "Name of topic", false);
Int32* CommonFields::PARTITION_ID = new Int32("partition", "Topic partition id", false);
Int16* CommonFields::ERROR_CODE = new Int16("error_code", "Response error code", false);
NullableStr* CommonFields::ERROR_MESSAGE = new NullableStr("error_message", "Response error message", false);
Int32* CommonFields::LEADER_EPOCH = new Int32("leader_epoch", "The leader epoch", false);
Int32* CommonFields::CURRENT_LEADER_EPOCH = new Int32("current_leader_epoch",
	"The current leader epoch, if provided, is used to fence consumers/replicas with old metadata. "
	"If the epoch provided by the client is larger than the current epoch known to the broker, then "
	"the UNKNOWN_LEADER_EPOCH error code will be returned. If the provided epoch is smaller, then "
	"the FENCED_LEADER_EPOCH error code will be returned.", false);

// Group APIs
Str* CommonFields::GROUP_ID = new Str("group_id", "The unique group identifier", false);
Int32* CommonFields::GENERATION_ID = new Int32("generation_id", "The generation of the group.", false);
Str* CommonFields::MEMBER_ID = new Str("member_id", "The member id assigned by the group "
	"coordinator or null if joining for the first time.", false);

// Transactional APIs
Str* CommonFields::TRANSACTIONAL_ID = new Str("transactional_id", "The transactional id corresponding to the transaction.", false);
NullableStr* CommonFields::NULLABLE_TRANSACTIONAL_ID = new NullableStr("transactional_id",
	"The transactional id or null if the producer is not transactional", false);
Int64* CommonFields::PRODUCER_ID = new Int64("producer_id", "Current producer id in use by the transactional id.", false);
Int16* CommonFields::PRODUCER_EPOCH = new Int16("producer_epoch", "Current epoch associated with the producer id.", false);

// ACL APIs
Int8* CommonFields::RESOURCE_TYPE = new Int8("resource_type", "The resource type", false);
Str* CommonFields::RESOURCE_NAME = new Str("resource_name", "The resource name", false);
NullableStr* CommonFields::RESOURCE_NAME_FILTER = new NullableStr("resource_name", "The resource name filter", false);
Int8* CommonFields::RESOURCE_PATTERN_TYPE = new Int8("resource_pattten_type", "The resource pattern type", PatternType::LITERAL, false);
Int8* CommonFields::RESOURCE_PATTERN_TYPE_FILTER = new Int8("resource_pattern_type_filter", "The resource pattern type filter", PatternType::LITERAL, false);
Str* CommonFields::PRINCIPAL = new Str("principal", "The ACL principal", false);
NullableStr* CommonFields::PRINCIPAL_FILTER = new NullableStr("principal", "The ACL principal filter", false);
Str* CommonFields::HOST = new Str("host", "The ACL host", false);
NullableStr* CommonFields::HOST_FILTER = new NullableStr("host", "The ACL host filter", false);
Int8* CommonFields::OPERATION = new Int8("operation", "The ACL operation", false);
Int8* CommonFields::PERMISSION_TYPE = new Int8("permission_type", "The ACL permission type", false);

Str* CommonFields::PRINCIPAL_TYPE = new Str("principal_type", "principalType of the Kafka principal", false);
Str* CommonFields::PRINCIPAL_NAME = new Str("name", "name of the Kafka principal", false);

Int64* CommonFields::COMMITTED_OFFSET = new Int64("offset",
	"Message offset to be committed", false);
NullableStr* CommonFields::COMMITTED_METADATA = new NullableStr("metadata",
	"Any associated metadata the client wants to keep.", false);
Int32* CommonFields::COMMITTED_LEADER_EPOCH = new Int32("leader_epoch",
	"The leader epoch, if provided is derived from the last consumed record. "
	"This is used by the consumer to check for log truncation and to ensure partition "
	"metadata is up to date following a group rebalance.", false);