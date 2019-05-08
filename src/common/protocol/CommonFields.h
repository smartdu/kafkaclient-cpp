#ifndef __KFK_COMMONFIELDS_H__
#define __KFK_COMMONFIELDS_H__

#pragma once
#include "Field.h"

class CommonFields
{
public:
	static Int32* THROTTLE_TIME_MS;
	static Str* TOPIC_NAME;
	static Int32* PARTITION_ID;
	static Int16* ERROR_CODE;
	static NullableStr* ERROR_MESSAGE;
	static Int32* LEADER_EPOCH;
	static Int32* CURRENT_LEADER_EPOCH;

	// Group APIs
	static Str* GROUP_ID;
	static Int32* GENERATION_ID;
	static Str* MEMBER_ID;

	// Transactional APIs
	static Str* TRANSACTIONAL_ID;
	static NullableStr* NULLABLE_TRANSACTIONAL_ID;
	static Int64* PRODUCER_ID;
	static Int16* PRODUCER_EPOCH;

	// ACL APIs
	static Int8* RESOURCE_TYPE;
	static Str* RESOURCE_NAME;
	static NullableStr* RESOURCE_NAME_FILTER;
	static Int8* RESOURCE_PATTERN_TYPE;
	static Int8* RESOURCE_PATTERN_TYPE_FILTER;
	static Str* PRINCIPAL;
	static NullableStr* PRINCIPAL_FILTER;
	static Str* HOST;
	static NullableStr* HOST_FILTER;
	static Int8* OPERATION;
	static Int8* PERMISSION_TYPE;

	static Str* PRINCIPAL_TYPE;
	static Str* PRINCIPAL_NAME;

	static Int64* COMMITTED_OFFSET;
	static NullableStr* COMMITTED_METADATA;
	static Int32* COMMITTED_LEADER_EPOCH;
};

#endif // !__KFK_COMMONFIELDS_H__
