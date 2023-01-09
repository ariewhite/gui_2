#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>
#include <QSqlQuery>>
namespace Ui {
class NewUserDialog;
}

class NewUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserDialog(QWidget *parent = nullptr);
    ~NewUserDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewUserDialog *ui;
};

#endif // NEWUSERDIALOG_H
