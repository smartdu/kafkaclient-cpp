#ifndef __KFK_OBJECT_H__
#define __KFK_OBJECT_H__

#pragma once
#include <string>

#define UNINIT_BEGIN(t)    \
class UNINIT##t    \
{   \
public: \
    virtual ~UNINIT##t()   \
    {

#define UNINIT_END(t)   \
}}; static UNINIT##t _UNINIT##t_;

#define DELETE_OBJ(obj) \
    do \
    {   \
        if (obj != NULL)    \
            delete obj; \
        obj = NULL; \
    } while (0);

class Object
{
public:
	virtual ~Object()
	{

	}

	virtual std::string toString();
};

#endif // !__KFK_OBJECT_H__
