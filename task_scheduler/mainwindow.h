#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BT_login_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> userDatabase;

    void loadUserData();
    void saveUserData();
    bool isEmailValid(const QString &email);
    bool isUserValid(const QString &email);
    void registerNewUser(const QString &email, const QString &password);
    bool isPasswordCorrect(const QString &email, const QString &password);
};

#endif
