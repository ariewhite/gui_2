#ifndef NEWTASKDIALOG_H
#define NEWTASKDIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlQuery>
#include <QString>

namespace Ui {
class NewTaskDialog;
}

class NewTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTaskDialog(QWidget *parent = nullptr);
    ~NewTaskDialog();

private slots:
    void on_progressBar_valueChanged(int value);

    void on_buttonBox_accepted();

private:
    Ui::NewTaskDialog *ui;
};

#endif // NEWTASKDIALOG_H
