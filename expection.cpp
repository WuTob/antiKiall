#include "expection.h"

Expection::Expection(QString errMsg,
                     ErrorType errType = ErrorType::UnFixable)
                   : errorMsg{errMsg}, errorType{errType}
{
}






bool pathNoExistError::solve()
{
    return false;
}

bool processStartError::solve()
{
    return false;
}
