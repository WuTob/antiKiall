#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passworddialog.h"
#include <QProcess>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <Windows.h>
#include <tchar.h>
#include <QSystemTrayIcon>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_StarButton_clicked();
    void on_StopButton_clicked();
    void tray_clicked(QSystemTrayIcon::ActivationReason);

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QSystemTrayIcon* tray;
};

void antiKill();

#endif // MAINWINDOW_H
