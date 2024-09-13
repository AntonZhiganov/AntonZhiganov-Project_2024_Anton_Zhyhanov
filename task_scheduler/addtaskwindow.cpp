#include "addtaskwindow.h"
#include "ui_addtaskwindow.h"
#include <QMessageBox>

addTaskWindow::addTaskWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTaskWindow)
{
    ui->setupUi(this);
}

addTaskWindow::~addTaskWindow() {
    delete ui;
}

QString addTaskWindow::getTaskName() const {
    return ui->LE_taskName->text();
}

QString addTaskWindow::getTaskDescription() const {
    return ui->TE_description->toPlainText();
}

QDate addTaskWindow::getStartDate() const {
    return ui->DE_start->date();
}

QDate addTaskWindow::getEndDate() const {
    return ui->DE_end->date();
}


void addTaskWindow::on_PB_createTask_clicked()
{
    if (getTaskName().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a task name.");
        return;
    }

    if (getStartDate() > getEndDate()) {
        QMessageBox::warning(this, "Error", "Start date cannot be later than end date.");
        return;
    }

    accept();
}

