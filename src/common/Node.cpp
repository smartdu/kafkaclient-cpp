#include "Node.h"

Node::Node(int id, const char *host, int port)
{

}

Node::Node(int id, const char *host, int port, const char *rack)
{
	this->id_ = id;
	this->host_ = host;
	this->idString_ = std::to_string(id);
	this->port_ = port;
	if (rack == NULL)
		rack_ = NULL;
	else
		rack_ = new std::string(rack);
}

Node* Node::noNode()
{
	return NO_NODE;
}

bool Node::isEmpty()
{
	return host_.empty() || port_ < 0;
}

int Node::id()
{
	return id_;
}

const char* Node::idString()
{
	return idString_.c_str();
}

const char* Node::host()
{
	return host_.c_str();
}

int Node::port()
{
	return port_;
}

bool Node::hasRack()
{
	return rack_ != NULL;
}

const char* Node::rack()
{
	return rack_->c_str();
}

std::string Node::toString()
{
	std::string rack = "null";
	if (rack_ != NULL)
		rack = *rack_;
	return host_ + ":" + std::to_string(port_) + " (id: " + idString_ + " rack: " + rack + ")";
}