#ifndef __KFK_METADATAREQUEST_H__
#define __KFK_METADATAREQUEST_H__

#pragma once
class Schema;
class Bool;

class MetadataRequest
{
public:
	static Schema** schemaVersions();

    static void destroy();

private:
	static const char *TOPICS_KEY_NAME;
	static Schema *METADATA_REQUEST_V0;
	static Schema *METADATA_REQUEST_V1;
	static Schema *METADATA_REQUEST_V2;
	static Schema *METADATA_REQUEST_V3;
	static Bool *ALLOW_AUTO_TOPIC_CREATION;
	static Schema *METADATA_REQUEST_V4;
	static Schema *METADATA_REQUEST_V5;
	static Schema *METADATA_REQUEST_V6;
	static Schema *METADATA_REQUEST_V7;
};

#endif // !__KFK_METADATAREQUEST_H__
