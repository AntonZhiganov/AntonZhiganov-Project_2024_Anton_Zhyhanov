#ifndef ADDTASKWINDOW_H
#define ADDTASKWINDOW_H

#include <QDialog>
#include <QDate>

namespace Ui {
class addTaskWindow;
}

class addTaskWindow : public QDialog {
    Q_OBJECT

public:
    explicit addTaskWindow(QWidget *parent = nullptr);
    ~addTaskWindow();

    QString getTaskName() const;
    QString getTaskDescription() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

private slots:
    void on_createButton_clicked();

    void on_PB_createTask_clicked();

private:
    Ui::addTaskWindow *ui;
};

#endif
