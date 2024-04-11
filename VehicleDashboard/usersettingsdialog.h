#ifndef USERSETTINGSDIALOG_H
#define USERSETTINGSDIALOG_H

#include <QDialog>
#include "addoperatordialog.h"

namespace Ui {
class userSettingsDialog;
}

class userSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit userSettingsDialog(QWidget *parent = nullptr);
    ~userSettingsDialog();

private slots:
    void on_addOperatorButton_clicked();

private:
    Ui::userSettingsDialog *ui;
    addOperatorDialog *addUserDialog;

};

#endif // USERSETTINGSDIALOG_H
