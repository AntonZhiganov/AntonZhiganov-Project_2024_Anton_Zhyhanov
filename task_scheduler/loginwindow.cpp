#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>
#include "workwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , workWindow(nullptr)
{
    ui->setupUi(this);


    connect(ui->Button_login, &QPushButton::clicked, this, &LoginWindow::on_Button_login_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Button_login_clicked()
{
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_pass->text();


    if (email == "user@example.com" && password == "password123") {
        if (!workWindow) {
            workWindow = new WorkWindow(this);
        }
        workWindow->show();
        workWindow->raise();
        workWindow->activateWindow();
        this->hide();
    } else {
        QMessageBox::warning(this, "Помилка входу", "Невірний логін або пароль.");
    }
}
