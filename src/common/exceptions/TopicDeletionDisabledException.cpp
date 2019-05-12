#include "TopicDeletionDisabledException.h"

TopicDeletionDisabledException::TopicDeletionDisabledException(std::string message)
    : ApiException(message.c_str())
{

}
