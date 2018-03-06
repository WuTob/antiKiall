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
    auto       passWord{ui->passWordEditer->text()};
    QByteArray passWordByte;

    passWordByte.append(passWord);

    QCryptographicHash hash{QCryptographicHash::Md5};
    hash.addData(passWordByte);

    QByteArray result{hash.result()};

    QString passWordHash;
    passWordHash.append(result.toHex());

    QFile data{"C://qt/secret.pwd"};
    if(data.open(QIODevice::ReadOnly))
    {
        auto correctHash{data.readAll()};

        if(passWordHash == correctHash){
            QDialog::accept();
        }
        else{
            QMessageBox::warning(this, "WrongPassWord", "WrongPassWord");
        }
    }
}
