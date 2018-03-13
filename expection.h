#ifndef EXPECTION_H
#define EXPECTION_H

#include "libraries.h"

enum class ErrorType;


class Expection
{
public:
    explicit Expection(QString, ErrorType);

    virtual QString   errMsg (){ return errorMsg; }
    virtual ErrorType errType(){ return errorType; }

    virtual bool solve() = 0;

    virtual ~Expection();

private:
    QString errorMsg;
    QString errorType;
};

class pathNoExistError : public Expection{ virtual bool solve(); };
class processStartError : public Expection { virtual bool solve(); };

enum class ErrorType
{
    UnFixable, Fixable
};

#endif // EXPECTION_H
