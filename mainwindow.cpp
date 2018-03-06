#include "mainwindow.h"
#include "ui_mainwindow.h"

void antiKill();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);

    timer->singleShot(1000, &antiKill);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isPythonActive()
{
    QProcess process;

    if(process.execute("tasklist"))
    {
        QString taskListString;
        taskListString.append(process.readAll());

        qDebug() << taskListString.indexOf("pythonw.exe");

        if(taskListString.indexOf("pythonw.exe") != -1){
            return true;
        }
        return false;
    }
    return false;
}

void runScript()
{
    ShellExecute(NULL, _T("open"), _T("1.pyw"), NULL, _T("C://qt/"), SW_SHOWNORMAL);
}

void antiKill()
{
    if(!isPythonActive()) runScript();
}
