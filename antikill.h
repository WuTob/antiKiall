#ifndef ANTIKILL_H
#define ANTIKILL_H

#include "libraries.h"

class AntiKill
{
public:
    AntiKill(QString processName, QString path);
    ~AntiKill();
    void run();
    void stop;


private:
    QTimer* timer;
    QString processName, path;
};

bool isProcessActive (QString processName);
bool isPathExist     (QString path);
bool runProcess      (QString path);


#endif // ANTIKILL_H
