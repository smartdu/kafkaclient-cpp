#ifndef __KFK_NODE_H__
#define __KFK_NODE_H__

#pragma once
#include <string>
#include "Object.h"

class Node
	: public Object
{
public:
	Node(int id, const char *host, int port);
	Node(int id, const char *host, int port, const char *rack);

	static Node* noNode();

	bool isEmpty();

	int id();

	const char* idString();

	const char* host();

	int port();

	bool hasRack();

	const char* rack();

	virtual std::string toString();

private:
	int id_;
	std::string idString_;
	std::string host_;
	int port_;
	std::string *rack_;
	static Node *NO_NODE;
};

#endif // !__KFK_NODE_H__
