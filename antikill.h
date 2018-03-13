#ifndef ANTIKILL_H
#define ANTIKILL_H

#include "libraries.h"
#include "expection.h"

class AntiKill
{
public:
    AntiKill(QString processName, QString path);
    ~AntiKill();
    void start();
    void stop();
    void run();

private:
    QTimer* timer;
    QString processName, path;
};

bool isProcessActive (QString processName);
bool isPathExist     (QString path);
bool runProcess      (QString path);
void logOutPut       (QString);


#endif // ANTIKILL_H
