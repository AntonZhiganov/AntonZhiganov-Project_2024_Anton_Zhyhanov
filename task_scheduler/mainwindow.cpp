#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadUserData();

    connect(ui->BT_login, &QPushButton::clicked,
            this, &MainWindow::on_BT_login_clicked);
}

MainWindow::~MainWindow()
{
    saveUserData();
    delete ui;
}

void MainWindow::loadUserData()
{
    QFile file("users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 2) {
                QString email = fields[0].trimmed();
                QString password = fields[1].trimmed();
                userDatabase.insert(email, password);
            }
        }
        file.close();
    }
}

void MainWindow::saveUserData()
{
    QFile file("users.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (auto it = userDatabase.begin(); it != userDatabase.end(); ++it) {
            out << it.key() << "," << it.value() << "\n";
        }
        file.close();
    }
}

bool MainWindow::isEmailValid(const QString &email)
{
    QRegularExpression regex(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}

bool MainWindow::isUserValid(const QString &email)
{
    return userDatabase.contains(email);
}

void MainWindow::registerNewUser(const QString &email, const QString &password)
{
    userDatabase.insert(email, password);
    saveUserData();
}

bool MainWindow::isPasswordCorrect(const QString &email, const QString &password)
{
    return userDatabase.value(email) == password;
}

void MainWindow::on_BT_login_clicked()
{
    QString email = ui->LE_email->text();
    QString password = ui->LE_pass->text();

    if (!isEmailValid(email)) {
        QMessageBox::warning(this, "Invalid format", "Please enter a valid email.");
        return;
    }

    if (!isUserValid(email)) {
        registerNewUser(email, password);
        QMessageBox::information(this, "Registration successful", "New user registered.");
    } else {
        if (!isPasswordCorrect(email, password)) {
            QMessageBox::warning(this, "Login error", "Invalid password.");
            return;
        }

        QMessageBox::information(this, "Login successful", "Welcome!");
    }

    WorkWindow *workWindow = new WorkWindow(this);
    workWindow->show();

    this->close();
}
