#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>
#include <QCryptographicHash>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class passWordDialog;
}

class passWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit passWordDialog(QWidget *parent = 0);
    ~passWordDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::passWordDialog *ui;
};

#endif // PASSWORDDIALOG_H
