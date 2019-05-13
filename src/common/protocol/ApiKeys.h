#ifndef __KFK_APIKEYS_H__
#define __KFK_APIKEYS_H__

#pragma once
#include <string>
#include <list>
#include "Object.h"
class Schema;
class Struct;
class ByteBuffer;

class ApiKeys
	: public Object
{
public:
	static ApiKeys* API_VERSIONS();
	static ApiKeys* METADATA();

	ApiKeys(int id, const char* name, Schema** requestSchemas, Schema** responseSchemas);
	ApiKeys(int id, const char* name, bool clusterAction, Schema** requestSchemas, Schema** responseSchemas);
	ApiKeys(int id, const char* name, bool clusterAction, char minRequiredInterBrokerMagic,
		Schema** requestSchemas, Schema** responseSchemas);
    virtual ~ApiKeys();

	virtual Struct* parseRequest(short version, ByteBuffer *buffer);

	virtual Struct* parseResponse(short version, ByteBuffer *buffer);

	Schema* requestSchema(short version);

	Schema* responseSchema(short version);

	short latestVersion();

	short oldestVersion();

	bool isVersionSupported(short apiVersion);

    static std::list<ApiKeys*> values();

protected:
	void init(int id, const char* name, bool clusterAction, char minRequiredInterBrokerMagic,
		Schema** requestSchemas, Schema** responseSchemas);

	virtual Struct* parseResponse(short version, ByteBuffer *buffer, short fallbackVersion);

private:
	static bool retainsBufferReference(Schema *schema);

	Schema* schemaFor(Schema **versions, short version);

public:
	short id;
	std::string name;
	bool clusterAction;
	char minRequiredInterBrokerMagic;
	Schema** requestSchemas;
	Schema** responseSchemas;
	bool requiresDelayedAllocation;
};

class ApiKeys_API_VERSIONS
	: public ApiKeys
{
public:
	ApiKeys_API_VERSIONS();

	virtual Struct* parseResponse(short version, ByteBuffer *buffer);
};

#endif // !__KFK_APIKEYS_H__
