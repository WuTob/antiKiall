#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StopButton->setEnabled(false);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &antiKill);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

bool isPythonActive()
{
    QProcess process;

    process.start("tasklist");

    if(process.waitForFinished())
    {
        QString taskListString;
        taskListString.append(process.readAll());

        qDebug() << taskListString.indexOf("python", 10);

        if(taskListString.indexOf("python") != -1){
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
    qDebug() << "test";
    if(!isPythonActive()) runScript();
}



void MainWindow::on_StarButton_clicked()
{
    timer->start(2000);
    ui->StopButton->setEnabled(true);
}

void MainWindow::on_StopButton_clicked()
{
    passWordDialog pwdDialog;
    pwdDialog.show();
    if(pwdDialog.exec() == QDialog::Accepted)
    {
        timer->stop();
        ui->StarButton->setEnabled(true);
        ui->StopButton->setEnabled(false);
    }
}
