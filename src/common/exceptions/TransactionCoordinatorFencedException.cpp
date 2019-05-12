#include "TransactionCoordinatorFencedException.h"

TransactionCoordinatorFencedException::TransactionCoordinatorFencedException(std::string message)
    : ApiException(message.c_str())
{

}
