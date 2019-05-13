#include "Errors.h"
#include "KafkaException.h"
#include "BrokerNotAvailableException.h"
#include "BufferOverflowException.h"
#include "BufferUnderflowException.h"
#include "ClusterAuthorizationException.h"
#include "ConcurrentTransactionsException.h"
#include "ControllerMovedException.h"
#include "CoordinatorLoadInProgressException.h"
#include "CoordinatorNotAvailableException.h"
#include "CorruptRecordException.h"
#include "DelegationTokenAuthorizationException.h"
#include "DelegationTokenDisabledException.h"
#include "DelegationTokenExpiredException.h"
#include "DelegationTokenNotFoundException.h"
#include "DelegationTokenOwnerMismatchException.h"
#include "DuplicateSequenceException.h"
#include "FencedLeaderEpochException.h"
#include "FetchSessionIdNotFoundException.h"
#include "GroupAuthorizationException.h"
#include "GroupIdNotFoundException.h"
#include "GroupMaxSizeReachedException.h"
#include "GroupNotEmptyException.h"
#include "IllegalArgumentException.h"
#include "IllegalGenerationException.h"
#include "IllegalSaslStateException.h"
#include "InconsistentGroupProtocolException.h"
#include "InvalidCommitOffsetSizeException.h"
#include "InvalidConfigurationException.h"
#include "InvalidFetchSessionEpochException.h"
#include "InvalidFetchSizeException.h"
#include "InvalidGroupIdException.h"
#include "InvalidMetadataException.h"
#include "InvalidPartitionsException.h"
#include "InvalidPidMappingException.h"
#include "InvalidPrincipalTypeException.h"
#include "InvalidReplicaAssignmentException.h"
#include "InvalidReplicationFactorException.h"
#include "InvalidRequestException.h"
#include "InvalidRequiredAcksException.h"
#include "InvalidSessionTimeoutException.h"
#include "InvalidTimestampException.h"
#include "InvalidTopicException.h"
#include "InvalidTxnStateException.h"
#include "InvalidTxnTimeoutException.h"
#include "KafkaStorageException.h"
#include "LeaderNotAvailableException.h"
#include "ListenerNotFoundException.h"
#include "LogDirNotFoundException.h"
#include "MemberIdRequiredException.h"
#include "NetworkException.h"
#include "NotControllerException.h"
#include "NotCoordinatorException.h"
#include "NotEnoughReplicasAfterAppendException.h"
#include "NotEnoughReplicasException.h"
#include "NotLeaderForPartitionException.h"
#include "OffsetMetadataTooLarge.h"
#include "OffsetNotAvailableException.h"
#include "OffsetOutOfRangeException.h"
#include "OperationNotAttemptedException.h"
#include "OutOfOrderSequenceException.h"
#include "PolicyViolationException.h"
#include "PreferredLeaderNotAvailableException.h"
#include "ProducerFencedException.h"
#include "ReassignmentInProgressException.h"
#include "RebalanceInProgressException.h"
#include "RecordBatchTooLargeException.h"
#include "RecordTooLargeException.h"
#include "ReplicaNotAvailableException.h"
#include "SaslAuthenticationException.h"
#include "SecurityDisabledException.h"
#include "StaleBrokerEpochException.h"
#include "TimeoutException.h"
#include "TopicAuthorizationException.h"
#include "TopicDeletionDisabledException.h"
#include "TopicExistsException.h"
#include "TransactionalIdAuthorizationException.h"
#include "TransactionCoordinatorFencedException.h"
#include "UnknownLeaderEpochException.h"
#include "UnknownMemberIdException.h"
#include "UnknownProducerIdException.h"
#include "UnknownServerException.h"
#include "UnknownTopicOrPartitionException.h"
#include "UnsupportedByAuthenticationException.h"
#include "UnsupportedCompressionTypeException.h"
#include "UnsupportedForMessageFormatException.h"
#include "UnsupportedSaslMechanismException.h"
#include "UnsupportedVersionException.h"

#include <stdio.h>

static std::map<short, Errors*> codeToError = std::map<short, Errors*>();

Errors* Errors::UNKNOWN_SERVER_ERROR = new Errors(-1, "The server experienced an unexpected error when processing the request.", UnknownServerException::new0());
Errors* Errors::NONE = new Errors(0, NULL);
Errors* Errors::OFFSET_OUT_OF_RANGE = new Errors(1, "The requested offset is not within the range of offsets maintained by the server.", OffsetOutOfRangeException::new0());
Errors* Errors::CORRUPT_MESSAGE = new Errors(2, "This message has failed its CRC checksum, exceeds the valid size, has a null key for a compacted topic, or is otherwise corrupt.", CorruptRecordException::new0());
Errors* Errors::UNKNOWN_TOPIC_OR_PARTITION = new Errors(3, "This server does not host this topic-partition.", UnknownTopicOrPartitionException::new0());
Errors* Errors::INVALID_FETCH_SIZE = new Errors(4, "The requested fetch size is invalid.", InvalidFetchSizeException::new0());
Errors* Errors::LEADER_NOT_AVAILABLE = new Errors(5, "There is no leader for this topic-partition as we are in the middle of a leadership election.", LeaderNotAvailableException::new0());
Errors* Errors::NOT_LEADER_FOR_PARTITION = new Errors(6, "This server is not the leader for that topic-partition.", NotLeaderForPartitionException::new0());
Errors* Errors::REQUEST_TIMED_OUT = new Errors(7, "The request timed out.", TimeoutException::new0());
Errors* Errors::BROKER_NOT_AVAILABLE = new Errors(8, "The broker is not available.", BrokerNotAvailableException::new0());
Errors* Errors::REPLICA_NOT_AVAILABLE = new Errors(9, "The replica is not available for the requested topic-partition.", ReplicaNotAvailableException::new0());
Errors* Errors::MESSAGE_TOO_LARGE = new Errors(10, "The request included a message larger than the max message size the server will accept.", RecordTooLargeException::new0());
Errors* Errors::STALE_CONTROLLER_EPOCH = new Errors(11, "The controller moved to another broker.", ControllerMovedException::new0());
Errors* Errors::OFFSET_METADATA_TOO_LARGE = new Errors(12, "The metadata field of the offset request was too large.", OffsetMetadataTooLarge::new0());
Errors* Errors::NETWORK_EXCEPTION = new Errors(13, "The server disconnected before a response was received.", NetworkException::new0());
Errors* Errors::COORDINATOR_LOAD_IN_PROGRESS = new Errors(14, "The coordinator is loading and hence can't process requests.", CoordinatorLoadInProgressException::new0());
Errors* Errors::COORDINATOR_NOT_AVAILABLE = new Errors(15, "The coordinator is not available.", CoordinatorNotAvailableException::new0());
Errors* Errors::NOT_COORDINATOR = new Errors(16, "This is not the correct coordinator.", NotCoordinatorException::new0());
Errors* Errors::INVALID_TOPIC_EXCEPTION = new Errors(17, "The request attempted to perform an operation on an invalid topic.", InvalidTopicException::new0());
Errors* Errors::RECORD_LIST_TOO_LARGE = new Errors(18, "The request included message batch larger than the configured segment size on the server.", RecordBatchTooLargeException::new0());
Errors* Errors::NOT_ENOUGH_REPLICAS = new Errors(19, "Messages are rejected since there are fewer in-sync replicas than required.", NotEnoughReplicasException::new0());
Errors* Errors::NOT_ENOUGH_REPLICAS_AFTER_APPEND = new Errors(20, "Messages are written to the log, but to fewer in-sync replicas than required.", NotEnoughReplicasAfterAppendException::new0());
Errors* Errors::INVALID_REQUIRED_ACKS = new Errors(21, "Produce request specified an invalid value for required acks.", InvalidRequiredAcksException::new0());
Errors* Errors::ILLEGAL_GENERATION = new Errors(22, "Specified group generation id is not valid.", IllegalGenerationException::new0());
Errors* Errors::INCONSISTENT_GROUP_PROTOCOL = new Errors(23, "The group member's supported protocols are incompatible with those of existing members or first group member tried to join with empty protocol type or empty protocol list.", InconsistentGroupProtocolException::new0());
Errors* Errors::INVALID_GROUP_ID = new Errors(24, "The configured groupId is invalid.", InvalidGroupIdException::new0());
Errors* Errors::UNKNOWN_MEMBER_ID = new Errors(25, "The coordinator is not aware of this member.", UnknownMemberIdException::new0());
Errors* Errors::INVALID_SESSION_TIMEOUT = new Errors(26, "The session timeout is not within the range allowed by the broker (as configured by group.min.session.timeout.ms and group.max.session.timeout.ms).", InvalidSessionTimeoutException::new0());
Errors* Errors::REBALANCE_IN_PROGRESS = new Errors(27, "The group is rebalancing, so a rejoin is needed.", RebalanceInProgressException::new0());
Errors* Errors::INVALID_COMMIT_OFFSET_SIZE = new Errors(28, "The committing offset data size is not valid.", InvalidCommitOffsetSizeException::new0());
Errors* Errors::TOPIC_AUTHORIZATION_FAILED = new Errors(29, "Topic authorization failed.", TopicAuthorizationException::new0());
Errors* Errors::GROUP_AUTHORIZATION_FAILED = new Errors(30, "Group authorization failed.", GroupAuthorizationException::new0());
Errors* Errors::CLUSTER_AUTHORIZATION_FAILED = new Errors(31, "Cluster authorization failed.", ClusterAuthorizationException::new0());
Errors* Errors::INVALID_TIMESTAMP = new Errors(32, "The timestamp of the message is out of acceptable range.", InvalidTimestampException::new0());
Errors* Errors::UNSUPPORTED_SASL_MECHANISM = new Errors(33, "The broker does not support the requested SASL mechanism.", UnsupportedSaslMechanismException::new0());
Errors* Errors::ILLEGAL_SASL_STATE = new Errors(34, "Request is not valid given the current SASL state.", IllegalSaslStateException::new0());
Errors* Errors::UNSUPPORTED_VERSION = new Errors(35, "The version of API is not supported.", UnsupportedVersionException::new0());
Errors* Errors::TOPIC_ALREADY_EXISTS = new Errors(36, "Topic with this name already exists.", TopicExistsException::new0());
Errors* Errors::INVALID_PARTITIONS = new Errors(37, "Number of partitions is below 1.", InvalidPartitionsException::new0());
Errors* Errors::INVALID_REPLICATION_FACTOR = new Errors(38, "Replication factor is below 1 or larger than the number of available brokers.", InvalidReplicationFactorException::new0());
Errors* Errors::INVALID_REPLICA_ASSIGNMENT = new Errors(39, "Replica assignment is invalid.", InvalidReplicaAssignmentException::new0());
Errors* Errors::INVALID_CONFIG = new Errors(40, "Configuration is invalid.", InvalidConfigurationException::new0());
Errors* Errors::NOT_CONTROLLER = new Errors(41, "This is not the correct controller for this cluster.", NotControllerException::new0());
Errors* Errors::INVALID_REQUEST = new Errors(42, "This most likely occurs because of a request being malformed by the client library or the message was sent to an incompatible broker. See the broker logs for more details.", InvalidRequestException::new0());
Errors* Errors::UNSUPPORTED_FOR_MESSAGE_FORMAT = new Errors(43, "The message format version on the broker does not support the request.", UnsupportedForMessageFormatException::new0());
Errors* Errors::POLICY_VIOLATION = new Errors(44, "Request parameters do not satisfy the configured policy.", PolicyViolationException::new0());
Errors* Errors::OUT_OF_ORDER_SEQUENCE_NUMBER = new Errors(45, "The broker received an out of order sequence number.", OutOfOrderSequenceException::new0());
Errors* Errors::DUPLICATE_SEQUENCE_NUMBER = new Errors(46, "The broker received a duplicate sequence number.", DuplicateSequenceException::new0());
Errors* Errors::INVALID_PRODUCER_EPOCH = new Errors(47, "Producer attempted an operation with an old epoch. Either there is a newer producer with the same transactionalId, or the producer's transaction has been expired by the broker.", ProducerFencedException::new0());
Errors* Errors::INVALID_TXN_STATE = new Errors(48, "The producer attempted a transactional operation in an invalid state.", InvalidTxnStateException::new0());
Errors* Errors::INVALID_PRODUCER_ID_MAPPING = new Errors(49, "The producer attempted to use a producer id which is not currently assigned to its transactional id.", InvalidPidMappingException::new0());
Errors* Errors::INVALID_TRANSACTION_TIMEOUT = new Errors(50, "The transaction timeout is larger than the maximum value allowed by the broker (as configured by transaction.max.timeout.ms).", InvalidTxnTimeoutException::new0());
Errors* Errors::CONCURRENT_TRANSACTIONS = new Errors(51, "The producer attempted to update a transaction while another concurrent operation on the same transaction was ongoing.", ConcurrentTransactionsException::new0());
Errors* Errors::TRANSACTION_COORDINATOR_FENCED = new Errors(52, "Indicates that the transaction coordinator sending a WriteTxnMarker is no longer the current coordinator for a given producer.", TransactionCoordinatorFencedException::new0());
Errors* Errors::TRANSACTIONAL_ID_AUTHORIZATION_FAILED = new Errors(53, "Transactional Id authorization failed.", TransactionalIdAuthorizationException::new0());
Errors* Errors::SECURITY_DISABLED = new Errors(54, "Security features are disabled.", SecurityDisabledException::new0());
Errors* Errors::OPERATION_NOT_ATTEMPTED = new Errors(55, "The broker did not attempt to execute this operation. This may happen for batched RPCs where some operations in the batch failed, causing the broker to respond without trying the rest.", OperationNotAttemptedException::new0());
Errors* Errors::KAFKA_STORAGE_ERROR = new Errors(56, "Disk error when trying to access log file on the disk.", KafkaStorageException::new0());
Errors* Errors::LOG_DIR_NOT_FOUND = new Errors(57, "The user-specified log directory is not found in the broker config.", LogDirNotFoundException::new0());
Errors* Errors::SASL_AUTHENTICATION_FAILED = new Errors(58, "SASL Authentication failed.", SaslAuthenticationException::new0());
Errors* Errors::UNKNOWN_PRODUCER_ID = new Errors(59, "This exception is raised by the broker if it could not locate the producer metadata "
	"associated with the producerId in question. This could happen if, for instance, the producer's records "
	"were deleted because their retention time had elapsed. Once the last records of the producerId are "
	"removed, the producer's metadata is removed from the broker, and future appends by the producer will "
	"return this exception.", UnknownProducerIdException::new0());
Errors* Errors::REASSIGNMENT_IN_PROGRESS = new Errors(60, "A partition reassignment is in progress.", ReassignmentInProgressException::new0());
Errors* Errors::DELEGATION_TOKEN_AUTH_DISABLED = new Errors(61, "Delegation Token feature is not enabled.", DelegationTokenDisabledException::new0());
Errors* Errors::DELEGATION_TOKEN_NOT_FOUND = new Errors(62, "Delegation Token is not found on server.", DelegationTokenNotFoundException::new0());
Errors* Errors::DELEGATION_TOKEN_OWNER_MISMATCH = new Errors(63, "Specified Principal is not valid Owner/Renewer.", DelegationTokenOwnerMismatchException::new0());
Errors* Errors::DELEGATION_TOKEN_REQUEST_NOT_ALLOWED = new Errors(64, "Delegation Token requests are not allowed on PLAINTEXT/1-way SSL "
	"channels and on delegation token authenticated channels.", UnsupportedByAuthenticationException::new0());
Errors* Errors::DELEGATION_TOKEN_AUTHORIZATION_FAILED = new Errors(65, "Delegation Token authorization failed.", DelegationTokenAuthorizationException::new0());
Errors* Errors::DELEGATION_TOKEN_EXPIRED = new Errors(66, "Delegation Token is expired.", DelegationTokenExpiredException::new0());
Errors* Errors::INVALID_PRINCIPAL_TYPE = new Errors(67, "Supplied principalType is not supported.", InvalidPrincipalTypeException::new0());
Errors* Errors::NON_EMPTY_GROUP = new Errors(68, "The group is not empty.", GroupNotEmptyException::new0());
Errors* Errors::GROUP_ID_NOT_FOUND = new Errors(69, "The group id does not exist.", GroupIdNotFoundException::new0());
Errors* Errors::FETCH_SESSION_ID_NOT_FOUND = new Errors(70, "The fetch session ID was not found.", FetchSessionIdNotFoundException::new0());
Errors* Errors::INVALID_FETCH_SESSION_EPOCH = new Errors(71, "The fetch session epoch is invalid.", InvalidFetchSessionEpochException::new0());
Errors* Errors::LISTENER_NOT_FOUND = new Errors(72, "There is no listener on the leader broker that matches the listener on which "
	"metadata request was processed.", ListenerNotFoundException::new0());
Errors* Errors::TOPIC_DELETION_DISABLED = new Errors(73, "Topic deletion is disabled.", TopicDeletionDisabledException::new0());
Errors* Errors::FENCED_LEADER_EPOCH = new Errors(74, "The leader epoch in the request is older than the epoch on the broker", FencedLeaderEpochException::new0());
Errors* Errors::UNKNOWN_LEADER_EPOCH = new Errors(75, "The leader epoch in the request is newer than the epoch on the broker", UnknownLeaderEpochException::new0());
Errors* Errors::UNSUPPORTED_COMPRESSION_TYPE = new Errors(76, "The requesting client does not support the compression type of given partition.", UnsupportedCompressionTypeException::new0());
Errors* Errors::STALE_BROKER_EPOCH = new Errors(77, "Broker epoch has changed", StaleBrokerEpochException::new0());
Errors* Errors::OFFSET_NOT_AVAILABLE = new Errors(78, "The leader high watermark has not caught up from a recent leader "
	"election so the offsets cannot be guaranteed to be monotonically increasing", OffsetNotAvailableException::new0());
Errors* Errors::MEMBER_ID_REQUIRED = new Errors(79, "The group member needs to have a valid member id before actually entering a consumer group", MemberIdRequiredException::new0());
Errors* Errors::PREFERRED_LEADER_NOT_AVAILABLE = new Errors(80, "The preferred leader was not available", PreferredLeaderNotAvailableException::new0());
Errors* Errors::GROUP_MAX_SIZE_REACHED = new Errors(81, "The consumer group has reached its max size.", GroupMaxSizeReachedException::new0());

Errors::Errors(int code, const char *defaultExceptionString, ApiException *exception)
{
	this->code_ = code;
	this->exception_ = exception;
	codeToError[code] = this;
}

Errors* Errors::forCode(short code)
{
	Errors *error = codeToError[code];
	if (error != NULL)
	{
		return error;
	}
	else
	{
		return UNKNOWN_SERVER_ERROR;
	}
}

short Errors::code()
{
	return code_;
}