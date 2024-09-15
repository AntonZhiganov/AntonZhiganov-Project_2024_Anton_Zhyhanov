#include "taskwindow.h"
#include "ui_taskwindow.h"
#include "addtaskwindow.h"

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

void TaskWindow::on_PB_addTask_clicked()
{
    addTaskWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString taskName = dialog.getTaskName();
        QString taskDescription = dialog.getTaskDescription();
        QDate startDate = dialog.getStartDate();
        QDate endDate = dialog.getEndDate();

        QString fullTaskDetails = taskName + ": " + taskDescription + " (" + startDate.toString() + " - " + endDate.toString() + ")";
        addTask(fullTaskDetails);
}
}

void TaskWindow::on_PB_deleteTask_clicked()
{
    QModelIndex selectedIndex = ui->LV_myTask->currentIndex();

    if (!selectedIndex.isValid()) {

        return;
    }

    QStringList taskList = model->stringList();
    taskList.removeAt(selectedIndex.row());
    model->setStringList(taskList);
}

