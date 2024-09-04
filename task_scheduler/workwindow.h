#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QMainWindow>
#include "ui_workwindow.h"  // Подключаем правильный заголовочный файл

namespace Ui {
class WorkWindow;  // Объявление класса
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

private:
    Ui::WorkWindow *ui;  // Указатель на сгенерированный интерфейс
};

#endif // WORKWINDOW_H
