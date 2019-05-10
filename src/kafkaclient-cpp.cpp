#include "kafkaclient-cpp.h"
#include "Struct.h"
#include "ApiVersionsResponse.h"
#include "ApiVersionsRequest.h"
#include "Errors.h"
#include "ByteBuffer.h"
#include "IllegalArgumentException.h"
#include "MetadataResponse.h"
#include "Node.h"

void test_version()
{
	char buffer[1024];
	FILE *file = fopen("version.bin", "rb");
	if (file == NULL)
	{
		printf("can't find version.bin\n");
		return;
	}
	int ret = fread(buffer, 1, sizeof(buffer), file);
	fclose(file);

	ByteBuffer *b = ByteBuffer::wrap(buffer + 8, ret - 8);
	short version = 2;

	ApiVersionsResponse *v = ApiVersionsResponse::parse(b, version);
	std::list<ApiVersion> versions = v->apiVersions();
	for (auto iter : versions)
	{
		printf("api_key = %d, min_version = %d, max_version = %d\n", iter.apiKey, iter.minVersion, iter.maxVersion);
	}
	delete v;
}

void test_metadata()
{
	char buffer[1024];
	FILE *file = fopen("metadata.bin", "rb");
	if (file == NULL)
	{
		printf("can't find metadata.bin\n");
		return;
	}
	int ret = fread(buffer, 1, sizeof(buffer), file);
	fclose(file);

	ByteBuffer *b = ByteBuffer::wrap(buffer + 8, ret - 8);
	short version = 7;

	MetadataResponse *v = MetadataResponse::parse(b, version);
	printf("cluster_id = %s\n", v->clusterId());
	printf("node_id = %d, host = %s, port = %d, rack = %s\n", v->controller()->id(), v->controller()->host(), v->controller()->port(), v->controller()->rack());
	delete v;
}

void test()
{
	test_version();
	test_metadata();
	return;
}
