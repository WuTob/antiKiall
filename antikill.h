#ifndef ANTIKILL_H
#define ANTIKILL_H

#include "libraries.h"
enum class RUN_STATE;

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

enum class RUN_STATE{
    SUCCEES, PATH_NO_EXIST, PROCESS_NO_RUNING
};

bool isProcessActive (QString processName);
bool isPathExist     (QString path);
bool runProcess      (QString path);

#endif // ANTIKILL_H
