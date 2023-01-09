#include "newtaskdialog.h"
#include "qsqlquery.h"
#include "ui_newtaskdialog.h"

NewTaskDialog::NewTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTaskDialog)
{
    ui->setupUi(this);
}

NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}

void NewTaskDialog::on_progressBar_valueChanged(int value)
{

}


void NewTaskDialog::on_buttonBox_accepted()
{
    QSqlQuery q = QSqlQuery();

    QString string = QString ("CALL new_task(description := '%1', "
                   "deadline_date := '%2',"
                   "task_priority_id := '%3',"
                   "task_type_id := '%4',"
                   "contract_id := '1'"
                   ");" ).arg(ui->label_desc->text())
            .arg(ui->dateTimeEdit->text())
            .arg(ui->comboBox->itemText(1))
            .arg(ui->comboBox_2->itemText(1));

    QSqlQuery query = QSqlQuery();

    query.exec(string);

    if (!query.next()){
        qDebug() << "ivnvalid value";
    }
}

