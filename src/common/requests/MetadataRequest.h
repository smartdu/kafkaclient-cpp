#ifndef __KFK_METADATAREQUEST_H__
#define __KFK_METADATAREQUEST_H__

#pragma once
class Schema;

class MetadataRequest
{
public:
	static Schema** schemaVersions();
};

#endif // !__KFK_METADATAREQUEST_H__
