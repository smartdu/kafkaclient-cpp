#include "Object.h"
#include "ApiKeys.h"
#include "Field.h"
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
            delete iter;
        }
    }
};

UNINIT __UNINIT__;

std::string Object::toString()
{
	return "";
}
