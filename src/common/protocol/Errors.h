#ifndef __KFK_ERRORS_H__
#define __KFK_ERRORS_H__

#pragma once
#include <map>
#include "Object.h"
#include "ApiException.h"

class Errors
	: public Object
{
public:
	static Errors* UNKNOWN_SERVER_ERROR;
	static Errors* NONE;
	static Errors* OFFSET_OUT_OF_RANGE;
	static Errors* CORRUPT_MESSAGE;
	static Errors* UNKNOWN_TOPIC_OR_PARTITION;
	static Errors* INVALID_FETCH_SIZE;
	static Errors* LEADER_NOT_AVAILABLE;
	static Errors* NOT_LEADER_FOR_PARTITION;
	static Errors* REQUEST_TIMED_OUT;
	static Errors* BROKER_NOT_AVAILABLE;
	static Errors* REPLICA_NOT_AVAILABLE;
	static Errors* MESSAGE_TOO_LARGE;
	static Errors* STALE_CONTROLLER_EPOCH;
	static Errors* OFFSET_METADATA_TOO_LARGE;
	static Errors* NETWORK_EXCEPTION;
	static Errors* COORDINATOR_LOAD_IN_PROGRESS;
	static Errors* COORDINATOR_NOT_AVAILABLE;
	static Errors* NOT_COORDINATOR;
	static Errors* INVALID_TOPIC_EXCEPTION;
	static Errors* RECORD_LIST_TOO_LARGE;
	static Errors* NOT_ENOUGH_REPLICAS;
	static Errors* NOT_ENOUGH_REPLICAS_AFTER_APPEND;
	static Errors* INVALID_REQUIRED_ACKS;
	static Errors* ILLEGAL_GENERATION;
	static Errors* INCONSISTENT_GROUP_PROTOCOL;
	static Errors* INVALID_GROUP_ID;
	static Errors* UNKNOWN_MEMBER_ID;
	static Errors* INVALID_SESSION_TIMEOUT;
	static Errors* REBALANCE_IN_PROGRESS;
	static Errors* INVALID_COMMIT_OFFSET_SIZE;
	static Errors* TOPIC_AUTHORIZATION_FAILED;
	static Errors* GROUP_AUTHORIZATION_FAILED;
	static Errors* CLUSTER_AUTHORIZATION_FAILED;
	static Errors* INVALID_TIMESTAMP;
	static Errors* UNSUPPORTED_SASL_MECHANISM;
	static Errors* ILLEGAL_SASL_STATE;
	static Errors* UNSUPPORTED_VERSION;
	static Errors* TOPIC_ALREADY_EXISTS;
	static Errors* INVALID_PARTITIONS;
	static Errors* INVALID_REPLICATION_FACTOR;
	static Errors* INVALID_REPLICA_ASSIGNMENT;
	static Errors* INVALID_CONFIG;
	static Errors* NOT_CONTROLLER;
	static Errors* INVALID_REQUEST;
	static Errors* UNSUPPORTED_FOR_MESSAGE_FORMAT;
	static Errors* POLICY_VIOLATION;
	static Errors* OUT_OF_ORDER_SEQUENCE_NUMBER;
	static Errors* DUPLICATE_SEQUENCE_NUMBER;
	static Errors* INVALID_PRODUCER_EPOCH;
	static Errors* INVALID_TXN_STATE;
	static Errors* INVALID_PRODUCER_ID_MAPPING;
	static Errors* INVALID_TRANSACTION_TIMEOUT;
	static Errors* CONCURRENT_TRANSACTIONS;
	static Errors* TRANSACTION_COORDINATOR_FENCED;
	static Errors* TRANSACTIONAL_ID_AUTHORIZATION_FAILED;
	static Errors* SECURITY_DISABLED;
	static Errors* OPERATION_NOT_ATTEMPTED;
	static Errors* KAFKA_STORAGE_ERROR;
	static Errors* LOG_DIR_NOT_FOUND;
	static Errors* SASL_AUTHENTICATION_FAILED;
	static Errors* UNKNOWN_PRODUCER_ID;
	static Errors* REASSIGNMENT_IN_PROGRESS;
	static Errors* DELEGATION_TOKEN_AUTH_DISABLED;
	static Errors* DELEGATION_TOKEN_NOT_FOUND;
	static Errors* DELEGATION_TOKEN_OWNER_MISMATCH;
	static Errors* DELEGATION_TOKEN_REQUEST_NOT_ALLOWED;
	static Errors* DELEGATION_TOKEN_AUTHORIZATION_FAILED;
	static Errors* DELEGATION_TOKEN_EXPIRED;
	static Errors* INVALID_PRINCIPAL_TYPE;
	static Errors* NON_EMPTY_GROUP;
	static Errors* GROUP_ID_NOT_FOUND;
	static Errors* FETCH_SESSION_ID_NOT_FOUND;
	static Errors* INVALID_FETCH_SESSION_EPOCH;
	static Errors* LISTENER_NOT_FOUND;
	static Errors* TOPIC_DELETION_DISABLED;
	static Errors* FENCED_LEADER_EPOCH;
	static Errors* UNKNOWN_LEADER_EPOCH;
	static Errors* UNSUPPORTED_COMPRESSION_TYPE;
	static Errors* STALE_BROKER_EPOCH;
	static Errors* OFFSET_NOT_AVAILABLE;
	static Errors* MEMBER_ID_REQUIRED;
	static Errors* PREFERRED_LEADER_NOT_AVAILABLE;
	static Errors* GROUP_MAX_SIZE_REACHED;

	Errors(int code, const char *defaultExceptionString, ApiException *exception = NULL);
    virtual ~Errors();

	static Errors* forCode(short code);

	short code();

    ApiException* exception()
	{
		return exception_;
	}

    ApiException* exception(const char *message)
    {
        if (message == NULL)
            return exception_;
        exception_->message(message);
        return exception_;
    }

    static void destroy();

private:
	short code_;
    ApiException *exception_;
};

#endif // !__KFK_ERRORS_H__
