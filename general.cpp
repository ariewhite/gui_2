#include "general.h"
#include "ui_general.h"
#include "newtaskdialog.h"
#include <QSqlTableModel>

General::General(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::General)
{
    ui->setupUi(this);
}

General::~General()
{
    delete ui;
}


void General::on_pushButton_employee_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);

    modal->setTable("employee");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_contract_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);

    modal->setTable("contract");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_client_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);

    modal->setTable("client_organisation");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_equipment_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);

    modal->setTable("equipment");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_current_task_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);
    QSqlQuery query;


    QString str = ("select description, status, creation_date, completion_date, deadline_date, contract_id from task "
                   "where executor_id = 9;");

    query.exec(str);

    while (query.next()){
        qDebug() << query.value(0).toString();
        //qDebug() << query.value(1).toString();
    }



    modal->setTable("select description, status, creation_date, completion_date, deadline_date, contract_id from task "
                   "where executor_id = 9;");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_task1_clicked()
{
    QSqlTableModel *modal = new QSqlTableModel(this);

    modal->setTable("task");
    modal->select();

    ui->tableView->setModel(modal);
}


void General::on_pushButton_newTask_clicked()
{
    qDebug() << "pressed";
    NewTaskDialog dlg;
    dlg.setModal(true);
    dlg.exec();

}


void General::on_pushButton_cn_clicked()
{
    NewTaskDialog dlg;
    dlg.setModal(true);
    dlg.exec();
}


void General::on_pushButton_clicked()
{
    NewUserDialog nwd;
    nwd.setModal(true);
    nwd.exec();
}

