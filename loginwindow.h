#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "general.h"
#include "databaseconnection.h"

#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>
#include <qDebug>
#include <iostream>
#include <QSqlRecord>
#include <QSqlError>
#include <QCryptographicHash>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT



public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

signals:
    void window();

private:
    Ui::LoginWindow *ui;
    General *general;
};
#endif // LOGINWINDOW_H
