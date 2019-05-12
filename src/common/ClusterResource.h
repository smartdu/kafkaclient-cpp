#ifndef __KFK_CLUSTERRESOURCE_H__
#define __KFK_CLUSTERRESOURCE_H__

#pragma once
#include "Object.h"
#include <string>

class ClusterResource
	: public Object
{
public:
	ClusterResource();
	ClusterResource(const char *clusterId);

	std::string clusterId()
	{
		return clusterId_;
	}

	virtual std::string toString();

private:
	std::string clusterId_;
};

#endif // !__KFK_CLUSTERRESOURCE_H__
