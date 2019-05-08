#include "kafkaclient-cpp.h"
#include "Struct.h"
#include "ApiVersionsResponse.h"
#include "ApiVersionsRequest.h"
#include "Errors.h"
#include "ByteBuffer.h"
#include "IllegalArgumentException.h"

void test()
{
	char buffer[1024];
	FILE *file = fopen("version.bin", "rb");
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
	return;
}