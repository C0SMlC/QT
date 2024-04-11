#include "usersettingsdialog.h"
#include "ui_usersettingsdialog.h"

userSettingsDialog::userSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userSettingsDialog)
{
    ui->setupUi(this);
}

userSettingsDialog::~userSettingsDialog()
{
    delete ui;
}

void userSettingsDialog::on_addOperatorButton_clicked()
{
    addUserDialog = new addOperatorDialog;
    addUserDialog->show();
}

