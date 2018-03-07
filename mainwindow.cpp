#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StarButton->setEnabled(false);
    setWindowFlags(Qt::WindowMinMaxButtonsHint);

    tray = new QSystemTrayIcon;
    tray->setIcon(QIcon("C://qt/timg.jpg"));
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(tray_clicked(QSystemTrayIcon::ActivationReason)));
    tray->show();

    setContextMenuPolicy(Qt::NoContextMenu);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &antiKill);
    timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete timer;
    tray->hide();
    delete tray;
    delete ui;
}

bool isPythonActive()
{
    QProcess process;
    QString result;

    process.start("tasklist", QStringList() << "/fi" << "imagename eq pythonw.exe");

    if(process.waitForFinished())
    {
        result.append(process.readAll());
        if(result.indexOf("PID") != -1)
        {
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
    ui->StarButton->setEnabled(false);
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

void MainWindow::tray_clicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;

    default:
        break;
    }
}
