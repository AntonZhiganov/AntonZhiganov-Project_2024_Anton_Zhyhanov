#include "workwindow.h"
#include "ui_workwindow.h"  // Подключаем правильный заголовочный файл

WorkWindow::WorkWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::WorkWindow)
{
    ui->setupUi(this);  // Инициализация интерфейса
}

WorkWindow::~WorkWindow()
{
    delete ui;  // Очистка ресурсов
}
