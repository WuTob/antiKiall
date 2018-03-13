#include "mainwindow.h"
#include "ui_mainwindow.h"

int ShellExecuteCode;
QString taskListOutPut;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StarButton->setEnabled(false);
    setWindowFlags(Qt::WindowMinMaxButtonsHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);

    tray = new QSystemTrayIcon;
    tray->setIcon(QIcon("timg.jpg"));
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

}

void runScript()
{
    QProcess process;

    const char* path = QDir::currentPath().toLocal8Bit().data();


}

void antiKill()
{
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
    passWordDialog pwdDialog(this);

    if(pwdDialog.exec() == QDialog::Accepted)
    {
        timer->stop();
        ui->StarButton->setEnabled(true);
        ui->StopButton->setEnabled(false);

        QFile file("output.log");
        if(file.open(QIODevice::WriteOnly)){
            QString output;
            output.append(taskListOutPut).append("\n").append(QString::number(ShellExecuteCode, 10));
            file.write(output.toLatin1());
        }

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

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
