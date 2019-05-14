#include "AbstractRequest.h"
#include "ApiKeys.h"
#include "UnsupportedVersionException.h"

AbstractRequest::AbstractRequest()
{

}

AbstractRequest::AbstractRequest(ApiKeys *api, short version)
{
    if (!api->isVersionSupported(version))
        throw UnsupportedVersionException("The " + api->toString() + " protocol does not support version " + std::to_string(version));
    this->version_ = version;
}

short AbstractRequest::version()
{
	return version_;
}