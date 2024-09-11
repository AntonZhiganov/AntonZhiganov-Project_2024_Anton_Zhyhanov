#include "workwindow.h"
#include "ui_workwindow.h"
#include "taskwindow.h"

WorkWindow::WorkWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
}

WorkWindow::~WorkWindow()
{
    delete ui;
}

void WorkWindow::on_BT_myTask_clicked()
{
    TaskWindow *taskWindow = new TaskWindow(this);
    taskWindow->show();

    this->close();
}


void WorkWindow::on_BT_newTask_clicked()
{
    TaskWindow *taskWindow = new TaskWindow(this);
    taskWindow->show();

    this->close();
}


void WorkWindow::on_BT_delTask_clicked()
{
    TaskWindow *taskWindow = new TaskWindow(this);
    taskWindow->show();

    this->close();
}

