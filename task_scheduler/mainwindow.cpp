#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->BT_login, &QPushButton::clicked,
            this, &MainWindow::on_BT_login_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BT_login_clicked()
{
    WorkWindow *workWindow = new WorkWindow(this);
    workWindow->show();
}
