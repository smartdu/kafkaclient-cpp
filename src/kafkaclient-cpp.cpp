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
	FILE *file = fopen("D:\\version.bin", "rb");
	int ret = fread(buffer, 1, sizeof(buffer), file);
	ByteBuffer *b = ByteBuffer::wrap(buffer + 8, ret - 8);

	short version = 2;

	ApiVersionsResponse *v = ApiVersionsResponse::parse(b, version);
	
	printf("");
	return;
}