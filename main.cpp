#include "mainwindow.h"
#include <QApplication>

bool checkOnly();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!checkOnly()) return 0;

    MainWindow w;

    w.hide();

    return a.exec();
}

bool checkOnly()
{
    HANDLE m_hMutex  =  CreateMutexA(NULL, FALSE,  "ToddWu" );

    if  (GetLastError()  ==  ERROR_ALREADY_EXISTS)  {
     CloseHandle(m_hMutex);
     m_hMutex  =  NULL;
      return  false;
    }
    else
        return true;
}
