#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    passWordDialog pwd;
    pwd.show();
    if(pwd.exec() == QDialog::Accepted)
    {
        QMessageBox::about(this,"succes","succes");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
