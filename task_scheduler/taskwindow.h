#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class TaskWindow;
}
QT_END_NAMESPACE

class TaskWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaskWindow(QWidget *parent = nullptr);
    ~TaskWindow();
    void addTask(const QString &task);

private:
    Ui::TaskWindow *ui;
    QStringListModel *model;
};

#endif // TASKWINDOW_H
