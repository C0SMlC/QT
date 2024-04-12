#ifndef USERSETTINGSDIALOG_H
#define USERSETTINGSDIALOG_H

#include <QDialog>
#include "addoperatordialog.h"
#include "models/userModel.h"

namespace Ui {
class userSettingsDialog;
}

class userSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit userSettingsDialog(QVector<UserModel>& users, QWidget *parent = nullptr);
    // userSettingsDialog();
    ~userSettingsDialog();

private slots:
    void on_addOperatorButton_clicked();
    void addUser(const QString& userName);
    void on_colorCombo_3_currentTextChanged(const QString &arg1);
    // void loadUpdatedDetails();

    void on_pushButton_2_clicked();

public slots:
        void renderUserComboBox(QVector<UserModel> users);

signals:
    void addUserToDb(const QString& userName);
    void updateUserInfo(UserModel user);

private:
    Ui::userSettingsDialog *ui;
    addOperatorDialog *addUserDialog;
    QVector<UserModel> users;
    UserModel selectedUser;

};

#endif // USERSETTINGSDIALOG_H
