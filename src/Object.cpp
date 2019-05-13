#include "Object.h"
#include "ApiKeys.h"
#include "Field.h"
#include "Type.h"
#include "Errors.h"
#include "ResponseHeader.h"
#include "Schema.h"
#include "Node.h"
#include <list>

class UNINIT
{
public:
    virtual ~UNINIT()
    {
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
        
        Errors::destroy();

        delete Node::noNode();

        std::list<Type*> values3 = Type::values();
        for (auto iter : values3)
        {
            Type::destroy(iter);
        }
    }
};

UNINIT __UNINIT__;

std::string Object::toString()
{
	return "";
}
