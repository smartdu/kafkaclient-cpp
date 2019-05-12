#ifndef __KFK_INETSOCKETADDRESS_H__
#define __KFK_INETSOCKETADDRESS_H__

#pragma once

class InetSocketAddress
{
public:
	const char* getHostString()
	{
		return "";
	}

	int getPort()
	{
		return 0;
	}
};

#endif // !__KFK_INETSOCKETADDRESS_H__
