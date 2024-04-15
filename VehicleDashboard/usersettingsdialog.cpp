#include "usersettingsdialog.h"
#include "ui_usersettingsdialog.h"

userSettingsDialog::userSettingsDialog(VehicleInfo currentUser, QVector<UserModel>& users, QWidget *parent) :
    users(users),
    QDialog(parent),
    ui(new Ui::userSettingsDialog)
{
    ui->setupUi(this);
    qDebug() << "fuewjierwiofr";

    renderUserComboBox(users);
    qDebug() << "fuewjierwiofr";

    renderPreviousValues(currentUser);
    qDebug() << "fuewjierwiofr";
}

void userSettingsDialog::renderPreviousValues(VehicleInfo currentUser){
    ui->colorCombo_3->setCurrentText(currentUser.getUserName());
    ui->colorCombo->setCurrentText(currentUser.getUserColor());
    ui->colorCombo_3->setCurrentText(currentUser.getUserMode());
}

void userSettingsDialog::renderUserComboBox(QVector<UserModel> users){
    this->users = users;
    ui->colorCombo_3->clear();

    QList<QString> userNames;
    for(auto& user: users){
        userNames.push_back(user.getUserName());
    }

    ui->colorCombo_3->addItems(userNames);
}

void userSettingsDialog::addUser(const QString& userName){
    emit addUserToDb(userName);
};

userSettingsDialog::~userSettingsDialog()
{
    delete ui;
}

void userSettingsDialog::on_addOperatorButton_clicked()
{
    addUserDialog = new addOperatorDialog;
    addUserDialog->show();
    connect(addUserDialog, &addOperatorDialog::addUserSignal, this, &userSettingsDialog::addUser);
}


void userSettingsDialog::on_colorCombo_3_currentTextChanged(const QString &arg1)
{

    for(auto& user: users){
        if(user.getUserName() == arg1){
            selectedUser = user;
            qDebug() << user.getUserName();
            qDebug() << user.getMode();
            qDebug() << selectedUser.getColor();
        }
    }

    QString color;
    QString mode;

    if(selectedUser.getColor() == "default"){
        color = "Default";
    }else{
        color = selectedUser.getColor();
    }

    if(selectedUser.getMode() == "default"){
        mode = "Eco";
    }else{
        mode = selectedUser.getMode();
    }

    ui->colorCombo->setCurrentText(color);
    ui->colorCombo_2->setCurrentText(mode);
}


void userSettingsDialog::on_pushButton_2_clicked()
{
    UserModel user(ui->colorCombo_3->currentText(), ui->colorCombo_2->currentText(), ui->colorCombo->currentText(),selectedUser.getDistance());

    qDebug() << user.getUserName();

    ui->colorCombo_3->setCurrentText(user.getUserName());
    ui->colorCombo->setCurrentText(user.getColor());
    ui->colorCombo_3->setCurrentText(user.getMode());

    emit updateUserInfo(user);
}

void userSettingsDialog::loadUpdatedDetails(){
    qDebug() << "Hii";
}
