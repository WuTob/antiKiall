#include "antikill.h"

AntiKill::AntiKill(QString processName, QString path)
{
    this->processName = processName;
    this->path = path;

}

AntiKill::~AntiKill()
{

}

void AntiKill::run()
{

}

bool isProcessActive(QString processName)
{
    QProcess process;
    QString result;

    process.start("tasklist", QStringList() << "/fi" << "imagename eq " + processName);

    if(process.waitForFinished())
    {
        result.append(process.readAll());
        taskListOutPut = result;
        qDebug() << taskListOutPut;
        if(result.indexOf("PID") != -1)
        {
            return true;
        }
        return false;
    }

    return false;
}

bool isPathExist(QString path)
{
    return QFile::exists(path);
}

bool runProcess(QString path)
{
    QProcess process;

    process.startDetached(path);
}
