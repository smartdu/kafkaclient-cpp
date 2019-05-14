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
#include "Schema.h"
#include "CommonFields.h"
#include "Node.h"
#include <list>

class UNINIT
{
public:
    virtual ~UNINIT()
    {
        Type::destroy();
        CommonFields::destroy();
        ApiVersionsRequest::destroy();
        ApiVersionsResponse::destroy();
        MetadataRequest::destroy();
        MetadataResponse::destroy();

        std::list<ApiKeys*> values1 = ApiKeys::values();
        for (auto iter : values1)
        {
            delete iter;
        }

        std::list<Field*> values2 = Field::values();
        for (auto iter : values2)
        {
            Field::destroy(iter);
        }

        std::list<ComplexArray*> values4 = ComplexArray::values();
        for (auto iter : values4)
        {
            delete iter;
        }

        std::list<Type*> values3 = Type::values();
        for (auto iter : values3)
        {
            Type::destroy(iter);
        }

        Schema::destroy(ResponseHeader::SCHEMA);

        Errors::destroy();

        delete Node::noNode();
    }
};

UNINIT __UNINIT__;

std::string Object::toString()
{
	return "";
}
