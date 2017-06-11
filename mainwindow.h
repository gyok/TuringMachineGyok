#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QDebug>
#include <programinterface.h>

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
    void ShowMessage();
    void ExitTuringMachine();
private:
    Ui::MainWindow *ui;
    programInterface *myGUI;
    int createMenus();

};

#endif // MAINWINDOW_H
