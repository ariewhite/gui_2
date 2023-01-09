#include "loginwindow.h"
#include "ui_loginwindow.h"



LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    general = new General();

    connect(general, &General::window, this, &LoginWindow::show);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// connection to db + authentification
void LoginWindow::on_pushButton_clicked()
{
   DatabaseConnection::connect_to_db();

   // get login and password from ui
   auto login = ui->lineEdit_login->text();
   auto password = ui->lineEdit_Password->text();

   // get hashing password to check the affiliation
   QByteArray y = password.toUtf8();
   auto x_password =  QCryptographicHash::hash(y, QCryptographicHash::Md5).toHex();

   // create sql request
   QSqlQuery query = QSqlQuery();

   // request body
   QString str = QString("select employee_passwords.hashed_password from employee_passwords "
                 "where employee_password_id  in "
                 "(select employee_id from employee where employee.login = '%1');--").arg(login);

   QString passwd;

   // execute sql request

   query.exec(str);

   while (query.next()){
       passwd = query.value(0).toString();
       qDebug() << query.lastQuery();
   }

   if (passwd == x_password){
       str = QString("Hi, %1").arg(login);
       qDebug() << str;
       general->show();
       this->close();

   }
   else {
       QMessageBox::critical(0, "Error", "Invalid  password or login.");
   }
}

