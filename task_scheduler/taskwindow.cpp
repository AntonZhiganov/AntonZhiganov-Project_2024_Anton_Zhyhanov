#include "taskwindow.h"
#include "ui_taskwindow.h"

TaskWindow::TaskWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaskWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList taskList = {"Task 1", "Task 2", "Task 3"};
    model->setStringList(taskList);

    ui->LV_myTask->setModel(model);
}

TaskWindow::~TaskWindow()
{
    delete ui;
}

void TaskWindow::addTask(const QString &task)
{
    QStringList taskList = model->stringList();
    taskList.append(task);
    model->setStringList(taskList);
}
