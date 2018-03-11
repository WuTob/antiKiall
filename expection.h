#ifndef EXPECTION_H
#define EXPECTION_H

#include "libraries.h"

enum class ErrorType;


class Expection
{
public:
    explicit Expection(QString);

    virtual QString   errMsg ();
    virtual ErrorType errType();

    virtual ~Expection();

private:
    QString errorMsg;
    QString errorType;
};

enum class ErrorType
{
    UnExpected, ExpectFix
};

#endif // EXPECTION_H
