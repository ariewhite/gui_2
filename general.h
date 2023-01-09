#ifndef GENERAL_H
#define GENERAL_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "newtaskdialog.h"
#include "newuserdialog.h"


namespace Ui {
class General;
}

class General : public QWidget
{
    Q_OBJECT

public:
    explicit General(QWidget *parent = nullptr);
    ~General();


signals:
    void window();
private slots:

    void on_pushButton_employee_clicked();

    void on_pushButton_contract_clicked();

    void on_pushButton_client_clicked();

    void on_pushButton_equipment_clicked();

    void on_pushButton_current_task_clicked();

    void on_pushButton_task1_clicked();

    void on_pushButton_newTask_clicked();

    void on_pushButton_cn_clicked();

    void on_pushButton_clicked();

private:
    Ui::General *ui;
};

#endif // GENERAL_H
