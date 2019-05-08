#ifndef __KFK_ABSTRACTREQUESTRESPONSE_H__
#define __KFK_ABSTRACTREQUESTRESPONSE_H__

#pragma once
class Struct;
class ByteBuffer;

class AbstractRequestResponse
{
public:
	static ByteBuffer* serialize(Struct *headerStruct, Struct *bodyStruct);
};

#endif // !__KFK_ABSTRACTREQUESTRESPONSE_H__
