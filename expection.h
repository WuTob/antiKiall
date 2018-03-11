#ifndef EXPECTION_H
#define EXPECTION_H

#include "libraries.h"

enum class ErrorType;


class Expection
{
    Expection();

    virtual QString   errMsg ();
    virtual ErrorType errType();
};

enum class ErrorType
{
    UnExpected, ExpectFix
};

#endif // EXPECTION_H
