#include "MetadataRequest.h"
#include "Schema.h"
#include "Field.h"
#include "Type.h"
#include "ArrayOf.h"
#include <stdio.h>

const char* MetadataRequest::TOPICS_KEY_NAME = "topics";

Schema* MetadataRequest::METADATA_REQUEST_V0 = new Schema(1,
	new Field(TOPICS_KEY_NAME, new ArrayOf(Type::STRING()), "An array of topics to fetch metadata for. If no topics are specified fetch metadata for all topics."));

Schema* MetadataRequest::METADATA_REQUEST_V1 = new Schema(1,
	new Field(TOPICS_KEY_NAME, ArrayOf::nullable(Type::STRING()), "An array of topics to fetch metadata for. If the topics array is null fetch metadata for all topics."));

Schema* MetadataRequest::METADATA_REQUEST_V2 = METADATA_REQUEST_V1;

Schema* MetadataRequest::METADATA_REQUEST_V3 = METADATA_REQUEST_V2;

Bool* MetadataRequest::ALLOW_AUTO_TOPIC_CREATION = new Bool("allow_auto_topic_creation",
	"If this and the broker config <code>auto.create.topics.enable</code> are true, topics that "
	"don't exist will be created by the broker. Otherwise, no topics will be created by the broker.");

Schema* MetadataRequest::METADATA_REQUEST_V4 = new Schema(2,
	new Field(TOPICS_KEY_NAME, ArrayOf::nullable(Type::STRING()), "An array of topics to fetch metadata for. "
		"If the topics array is null fetch metadata for all topics."),
	ALLOW_AUTO_TOPIC_CREATION);

Schema* MetadataRequest::METADATA_REQUEST_V5 = METADATA_REQUEST_V4;

Schema* MetadataRequest::METADATA_REQUEST_V6 = METADATA_REQUEST_V5;

Schema* MetadataRequest::METADATA_REQUEST_V7 = METADATA_REQUEST_V6;

Schema** MetadataRequest::schemaVersions()
{
	static Schema* schemas[] = { METADATA_REQUEST_V0, METADATA_REQUEST_V1, METADATA_REQUEST_V2, METADATA_REQUEST_V3,
		METADATA_REQUEST_V4, METADATA_REQUEST_V5, METADATA_REQUEST_V6, METADATA_REQUEST_V7, NULL };
	return schemas;
}