#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passworddialog.h"
#include "libraries.h"

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

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QSystemTrayIcon* tray;
    QPoint last;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

void antiKill();

#endif // MAINWINDOW_H
