#include "newuserdialog.h"
#include "ui_newuserdialog.h"
#include "config.h"

NewUserDialog::NewUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUserDialog)
{
    ui->setupUi(this);
}

NewUserDialog::~NewUserDialog()
{
    delete ui;
}

void NewUserDialog::on_buttonBox_accepted()
{
    auto login = ui->lineEdit_login->text();
    auto firstName = ui->lineEdit_first->text();
    auto secondName = ui->lineEdit_second->text();
    auto phone = ui->lineEdit_phone->text();
    auto mail = ui->lineEdit_mail->text();
    auto password = ui->lineEdit_Password->text();



    QString str = QString("call new_employee('%1',"
                          "'%2',"
                          "'%3',"
                          "'%4',"
                          "'%5',"
                          "'2',"
                          "'%6');").arg(login).arg(firstName).arg(secondName)
                        .arg(phone).arg(mail).arg(hashing(password));

    QSqlQuery q = QSqlQuery();

    q.exec(str);

}

