#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QMainWindow>
#include "ui_workwindow.h"

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

private slots:
    void on_BT_myTask_clicked();

    void on_BT_newTask_clicked();

    void on_BT_delTask_clicked();

private:
    Ui::WorkWindow *ui;
};

#endif
