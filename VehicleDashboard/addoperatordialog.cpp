#include "addoperatordialog.h"
#include "ui_addoperatordialog.h"

addOperatorDialog::addOperatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addOperatorDialog)
{
    ui->setupUi(this);
}

addOperatorDialog::~addOperatorDialog()
{
    delete ui;
}

void addOperatorDialog::on_pushButton_clicked()
{
    QString userName = ui->lineEdit->text();
    emit addUserSignal(userName);
}

