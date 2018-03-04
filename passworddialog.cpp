#include "passworddialog.h"
#include "ui_passworddialog.h"
#include <QDebug>

passWordDialog::passWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passWordDialog)
{
    ui->setupUi(this);
}

passWordDialog::~passWordDialog()
{
    delete ui;
}

void passWordDialog::on_pushButton_clicked()
{
    QString md5;
    QString pwd = ui->passWordEditer->toPlainText();

    QByteArray result = QCryptographicHash::hash( pwd.toLatin1(), QCryptographicHash::Md5);
    md5.append(result);

    QFile data("D://secret.pwd");
    if(data.open(QFile::ReadOnly))
    {
        QString MD5(data.readAll());
        qDebug() << MD5 << " " << md5 << " " << pwd;
        if(md5 == MD5) QDialog::accept();
        else QMessageBox::warning(this,"WrongPassWord","WrongPassWord");
    }

}
