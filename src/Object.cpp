#include "Object.h"
#include "ApiKeys.h"
#include "Field.h"
#include "Type.h"
#include "Errors.h"
#include "ResponseHeader.h"
#include "MetadataRequest.h"
#include "MetadataResponse.h"
#include "ApiVersionsRequest.h"
#include "ApiVersionsResponse.h"
#include "OffsetFetchRequest.h"
#include "OffsetFetchResponse.h"
#include "Schema.h"
#include "CommonFields.h"
#include "Node.h"
#include <list>

UNINIT_BEGIN(Object)
    CommonFields::destroy();
    ApiVersionsRequest::destroy();
    ApiVersionsResponse::destroy();
    MetadataRequest::destroy();
    MetadataResponse::destroy();
    OffsetFetchRequest::destroy();
    OffsetFetchResponse::destroy();
UNINIT_END(Object)

std::string Object::toString()
{
	return "";
}
