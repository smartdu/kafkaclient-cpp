#include "Object.h"
#include "ApiKeys.h"
#include <list>

class UNINIT
{
public:
    virtual ~UNINIT()
    {
        std::list<ApiKeys*> values = ApiKeys::values();
        for (auto iter : values)
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
