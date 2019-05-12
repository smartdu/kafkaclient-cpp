#include "ClusterResource.h"

ClusterResource::ClusterResource()
{

}

ClusterResource::ClusterResource(const char *clusterId)
	: clusterId_(clusterId)
{

}

std::string ClusterResource::toString()
{
	return "ClusterResource(clusterId=" + clusterId_ + ")";
}