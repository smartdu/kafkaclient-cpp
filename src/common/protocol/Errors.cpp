#include "Errors.h"
#include <stdio.h>

static std::map<short, Errors*> codeToError = std::map<short, Errors*>();

Errors* Errors::UNKNOWN_SERVER_ERROR = new Errors(-1, "The server experienced an unexpected error when processing the request.", UnknownServerException::new);
Errors* Errors::NONE = new Errors(0, NULL);
Errors* Errors::OFFSET_OUT_OF_RANGE = new Errors(1, "The requested offset is not within the range of offsets maintained by the server.", OffsetOutOfRangeException::new);
Errors* Errors::CORRUPT_MESSAGE = new Errors(2, "This message has failed its CRC checksum, exceeds the valid size, has a null key for a compacted topic, or is otherwise corrupt.", CorruptRecordException::new);
Errors* Errors::UNKNOWN_TOPIC_OR_PARTITION = new Errors(3, "This server does not host this topic-partition.", UnknownTopicOrPartitionException::new);
Errors* Errors::INVALID_FETCH_SIZE = new Errors(4, "The requested fetch size is invalid.", InvalidFetchSizeException::new);
Errors* Errors::LEADER_NOT_AVAILABLE = new Errors(5, "There is no leader for this topic-partition as we are in the middle of a leadership election.", LeaderNotAvailableException::new);
Errors* Errors::NOT_LEADER_FOR_PARTITION = new Errors(6, "This server is not the leader for that topic-partition.", NotLeaderForPartitionException::new);
Errors* Errors::REQUEST_TIMED_OUT = new Errors(7, "The request timed out.", TimeoutException::new);
Errors* Errors::BROKER_NOT_AVAILABLE = new Errors(8, "The broker is not available.", BrokerNotAvailableException::new);
Errors* Errors::REPLICA_NOT_AVAILABLE = new Errors(9, "The replica is not available for the requested topic-partition.", ReplicaNotAvailableException::new);
Errors* Errors::MESSAGE_TOO_LARGE = new Errors(10, "The request included a message larger than the max message size the server will accept.", RecordTooLargeException::new);
Errors* Errors::STALE_CONTROLLER_EPOCH = new Errors(11, "The controller moved to another broker.", ControllerMovedException::new);
Errors* Errors::OFFSET_METADATA_TOO_LARGE = new Errors(12, "The metadata field of the offset request was too large.", OffsetMetadataTooLarge::new);
Errors* Errors::NETWORK_EXCEPTION = new Errors(13, "The server disconnected before a response was received.", NetworkException::new);
Errors* Errors::COORDINATOR_LOAD_IN_PROGRESS = new Errors(14, "The coordinator is loading and hence can't process requests.", CoordinatorLoadInProgressException::new);
Errors* Errors::COORDINATOR_NOT_AVAILABLE = new Errors(15, "The coordinator is not available.", CoordinatorNotAvailableException::new);
Errors* Errors::NOT_COORDINATOR = new Errors(16, "This is not the correct coordinator.", NotCoordinatorException::new);
Errors* Errors::INVALID_TOPIC_EXCEPTION = new Errors(17, "The request attempted to perform an operation on an invalid topic.", InvalidTopicException::new);
Errors* Errors::RECORD_LIST_TOO_LARGE = new Errors(18, "The request included message batch larger than the configured segment size on the server.", RecordBatchTooLargeException::new);
Errors* Errors::NOT_ENOUGH_REPLICAS = new Errors(19, "Messages are rejected since there are fewer in-sync replicas than required.", NotEnoughReplicasException::new);
Errors* Errors::NOT_ENOUGH_REPLICAS_AFTER_APPEND = new Errors(20, "Messages are written to the log, but to fewer in-sync replicas than required.", NotEnoughReplicasAfterAppendException::new);
Errors* Errors::INVALID_REQUIRED_ACKS = new Errors(21, "Produce request specified an invalid value for required acks.", InvalidRequiredAcksException::new);
Errors* Errors::ILLEGAL_GENERATION = new Errors(22, "Specified group generation id is not valid.", IllegalGenerationException::new);
Errors* Errors::INCONSISTENT_GROUP_PROTOCOL = new Errors(23, "The group member's supported protocols are incompatible with those of existing members or first group member tried to join with empty protocol type or empty protocol list.", InconsistentGroupProtocolException::new);
Errors* Errors::INVALID_GROUP_ID = new Errors(24, "The configured groupId is invalid.", InvalidGroupIdException::new);
Errors* Errors::UNKNOWN_MEMBER_ID = new Errors(25, "The coordinator is not aware of this member.", UnknownMemberIdException::new);
Errors* Errors::INVALID_SESSION_TIMEOUT = new Errors(26, "The session timeout is not within the range allowed by the broker (as configured by group.min.session.timeout.ms and group.max.session.timeout.ms).", InvalidSessionTimeoutException::new);
Errors* Errors::REBALANCE_IN_PROGRESS = new Errors(27, "The group is rebalancing, so a rejoin is needed.", RebalanceInProgressException::new);
Errors* Errors::INVALID_COMMIT_OFFSET_SIZE = new Errors(28, "The committing offset data size is not valid.", InvalidCommitOffsetSizeException::new);
Errors* Errors::TOPIC_AUTHORIZATION_FAILED = new Errors(29, "Topic authorization failed.", TopicAuthorizationException::new);
Errors* Errors::GROUP_AUTHORIZATION_FAILED = new Errors(30, "Group authorization failed.", GroupAuthorizationException::new);
Errors* Errors::CLUSTER_AUTHORIZATION_FAILED = new Errors(31, "Cluster authorization failed.", ClusterAuthorizationException::new);
Errors* Errors::INVALID_TIMESTAMP = new Errors(32, "The timestamp of the message is out of acceptable range.", InvalidTimestampException::new);
Errors* Errors::UNSUPPORTED_SASL_MECHANISM = new Errors(33, "The broker does not support the requested SASL mechanism.", UnsupportedSaslMechanismException::new);
Errors* Errors::ILLEGAL_SASL_STATE = new Errors(34, "Request is not valid given the current SASL state.", IllegalSaslStateException::new);
Errors* Errors::UNSUPPORTED_VERSION = new Errors(35, "The version of API is not supported.", UnsupportedVersionException::new);
Errors* Errors::TOPIC_ALREADY_EXISTS = new Errors(36, "Topic with this name already exists.", TopicExistsException::new);
Errors* Errors::INVALID_PARTITIONS = new Errors(37, "Number of partitions is below 1.", InvalidPartitionsException::new);
Errors* Errors::INVALID_REPLICATION_FACTOR = new Errors(38, "Replication factor is below 1 or larger than the number of available brokers.", InvalidReplicationFactorException::new);
Errors* Errors::INVALID_REPLICA_ASSIGNMENT = new Errors(39, "Replica assignment is invalid.", InvalidReplicaAssignmentException::new);
Errors* Errors::INVALID_CONFIG = new Errors(40, "Configuration is invalid.", InvalidConfigurationException::new);
Errors* Errors::NOT_CONTROLLER = new Errors(41, "This is not the correct controller for this cluster.", NotControllerException::new);
Errors* Errors::INVALID_REQUEST = new Errors(42, "This most likely occurs because of a request being malformed by the client library or the message was sent to an incompatible broker. See the broker logs for more details.", InvalidRequestException::new);
Errors* Errors::UNSUPPORTED_FOR_MESSAGE_FORMAT = new Errors(43, "The message format version on the broker does not support the request.", UnsupportedForMessageFormatException::new);
Errors* Errors::POLICY_VIOLATION = new Errors(44, "Request parameters do not satisfy the configured policy.", PolicyViolationException::new);
Errors* Errors::OUT_OF_ORDER_SEQUENCE_NUMBER = new Errors(45, "The broker received an out of order sequence number.", OutOfOrderSequenceException::new);
Errors* Errors::DUPLICATE_SEQUENCE_NUMBER = new Errors(46, "The broker received a duplicate sequence number.", DuplicateSequenceException::new);
Errors* Errors::INVALID_PRODUCER_EPOCH = new Errors(47, "Producer attempted an operation with an old epoch. Either there is a newer producer with the same transactionalId, or the producer's transaction has been expired by the broker.", ProducerFencedException::new);
Errors* Errors::INVALID_TXN_STATE = new Errors(48, "The producer attempted a transactional operation in an invalid state.", InvalidTxnStateException::new);
Errors* Errors::INVALID_PRODUCER_ID_MAPPING = new Errors(49, "The producer attempted to use a producer id which is not currently assigned to its transactional id.", InvalidPidMappingException::new);
Errors* Errors::INVALID_TRANSACTION_TIMEOUT = new Errors(50, "The transaction timeout is larger than the maximum value allowed by the broker (as configured by transaction.max.timeout.ms).", InvalidTxnTimeoutException::new);
Errors* Errors::CONCURRENT_TRANSACTIONS = new Errors(51, "The producer attempted to update a transaction while another concurrent operation on the same transaction was ongoing.", ConcurrentTransactionsException::new);
Errors* Errors::TRANSACTION_COORDINATOR_FENCED = new Errors(52, "Indicates that the transaction coordinator sending a WriteTxnMarker is no longer the current coordinator for a given producer.", TransactionCoordinatorFencedException::new);
Errors* Errors::TRANSACTIONAL_ID_AUTHORIZATION_FAILED = new Errors(53, "Transactional Id authorization failed.", TransactionalIdAuthorizationException::new);
Errors* Errors::SECURITY_DISABLED = new Errors(54, "Security features are disabled.", SecurityDisabledException::new);
Errors* Errors::OPERATION_NOT_ATTEMPTED = new Errors(55, "The broker did not attempt to execute this operation. This may happen for batched RPCs where some operations in the batch failed, causing the broker to respond without trying the rest.", OperationNotAttemptedException::new);
Errors* Errors::KAFKA_STORAGE_ERROR = new Errors(56, "Disk error when trying to access log file on the disk.", KafkaStorageException::new);
Errors* Errors::LOG_DIR_NOT_FOUND = new Errors(57, "The user-specified log directory is not found in the broker config.", LogDirNotFoundException::new);
Errors* Errors::SASL_AUTHENTICATION_FAILED = new Errors(58, "SASL Authentication failed.", SaslAuthenticationException::new);
Errors* Errors::UNKNOWN_PRODUCER_ID = new Errors(59, "This exception is raised by the broker if it could not locate the producer metadata "
	"associated with the producerId in question. This could happen if, for instance, the producer's records "
	"were deleted because their retention time had elapsed. Once the last records of the producerId are "
	"removed, the producer's metadata is removed from the broker, and future appends by the producer will "
	"return this exception.", UnknownProducerIdException::new);
Errors* Errors::REASSIGNMENT_IN_PROGRESS = new Errors(60, "A partition reassignment is in progress.", ReassignmentInProgressException::new);
Errors* Errors::DELEGATION_TOKEN_AUTH_DISABLED = new Errors(61, "Delegation Token feature is not enabled.", DelegationTokenDisabledException::new);
Errors* Errors::DELEGATION_TOKEN_NOT_FOUND = new Errors(62, "Delegation Token is not found on server.", DelegationTokenNotFoundException::new);
Errors* Errors::DELEGATION_TOKEN_OWNER_MISMATCH = new Errors(63, "Specified Principal is not valid Owner/Renewer.", DelegationTokenOwnerMismatchException::new);
Errors* Errors::DELEGATION_TOKEN_REQUEST_NOT_ALLOWED = new Errors(64, "Delegation Token requests are not allowed on PLAINTEXT/1-way SSL "
	"channels and on delegation token authenticated channels.", UnsupportedByAuthenticationException::new);
Errors* Errors::DELEGATION_TOKEN_AUTHORIZATION_FAILED = new Errors(65, "Delegation Token authorization failed.", DelegationTokenAuthorizationException::new);
Errors* Errors::DELEGATION_TOKEN_EXPIRED = new Errors(66, "Delegation Token is expired.", DelegationTokenExpiredException::new);
Errors* Errors::INVALID_PRINCIPAL_TYPE = new Errors(67, "Supplied principalType is not supported.", InvalidPrincipalTypeException::new);
Errors* Errors::NON_EMPTY_GROUP = new Errors(68, "The group is not empty.", GroupNotEmptyException::new);
Errors* Errors::GROUP_ID_NOT_FOUND = new Errors(69, "The group id does not exist.", GroupIdNotFoundException::new);
Errors* Errors::FETCH_SESSION_ID_NOT_FOUND = new Errors(70, "The fetch session ID was not found.", FetchSessionIdNotFoundException::new);
Errors* Errors::INVALID_FETCH_SESSION_EPOCH = new Errors(71, "The fetch session epoch is invalid.", InvalidFetchSessionEpochException::new);
Errors* Errors::LISTENER_NOT_FOUND = new Errors(72, "There is no listener on the leader broker that matches the listener on which "
	"metadata request was processed.", ListenerNotFoundException::new);
Errors* Errors::TOPIC_DELETION_DISABLED = new Errors(73, "Topic deletion is disabled.", TopicDeletionDisabledException::new);
Errors* Errors::FENCED_LEADER_EPOCH = new Errors(74, "The leader epoch in the request is older than the epoch on the broker", FencedLeaderEpochException::new);
Errors* Errors::UNKNOWN_LEADER_EPOCH = new Errors(75, "The leader epoch in the request is newer than the epoch on the broker", UnknownLeaderEpochException::new);
Errors* Errors::UNSUPPORTED_COMPRESSION_TYPE = new Errors(76, "The requesting client does not support the compression type of given partition.", UnsupportedCompressionTypeException::new);
Errors* Errors::STALE_BROKER_EPOCH = new Errors(77, "Broker epoch has changed", StaleBrokerEpochException::new);
Errors* Errors::OFFSET_NOT_AVAILABLE = new Errors(78, "The leader high watermark has not caught up from a recent leader "
	"election so the offsets cannot be guaranteed to be monotonically increasing", OffsetNotAvailableException::new);
Errors* Errors::MEMBER_ID_REQUIRED = new Errors(79, "The group member needs to have a valid member id before actually entering a consumer group", MemberIdRequiredException::new);
Errors* Errors::PREFERRED_LEADER_NOT_AVAILABLE = new Errors(80, "The preferred leader was not available", PreferredLeaderNotAvailableException::new);
Errors* Errors::GROUP_MAX_SIZE_REACHED = new Errors(81, "The consumer group has reached its max size.", GroupMaxSizeReachedException::new);

Errors::Errors(int code, const char *defaultExceptionString, KafkaException *exception)
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