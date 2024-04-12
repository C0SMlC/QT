#include "vehicledashboard.h"
#include "./ui_vehicledashboard.h"

VehicleDashboard::VehicleDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehicleDashboard),
    provider(new dataprovider)

{
    ui->setupUi(this);
    this->setWindowTitle("Start Menu");


    vehicleStartedTimer = new QTimer;
    vehicleStartedTimer->setSingleShot(false);
    vehicleStartedTimer->setInterval(5000);

    connect(vehicleStartedTimer, &QTimer::timeout, this, &VehicleDashboard::handleTimeout);
    connect(provider, &dataprovider::usersUpdated, this, &VehicleDashboard::handleUpdates);

   // vehicleStartedTimer->start();
}

void VehicleDashboard::handleUpdates(){
    qDebug() << "Signal recieved \n";
    emit updateDetails(provider->getAllUsers());
}

void VehicleDashboard::handleTimeout(){

    if(batteryLevel > 0) batteryLevel--;
    qDebug() << "Battery level decreased, Battery Level Is,"<<batteryLevel;
}

VehicleDashboard::~VehicleDashboard()
{
   // provider->updateBatteryLevel(batteryLevel);
   // provider->updateTotalDistanceTravelled(totalDistanceTravelled);

    delete provider;
    delete vehicleStartedTimer;
    delete ui;
}


void VehicleDashboard::on_startButton_clicked()
{
    if(!newVehicleInstrumentPanel){
        VehicleInfo previosusInfo = provider->getVehicleInfo();
        newVehicleInstrumentPanel = new VehicleInstrumentPanel(previosusInfo);
        newVehicleInstrumentPanel->show();
    }

    if(!isVehicleStarted){
        ui->startButton->setStyleSheet("Background-color: '#078080'; border-radius:62px;");
        ui->startButton->setText("Stop");
        isVehicleStarted = true;
    }else{
        ui->startButton->setStyleSheet("Background-color: '#f45d48'; border-radius:62px;");
        ui->startButton->setText("Start");
        isVehicleStarted = false;
    }
}


void VehicleDashboard::on_userSettingsButton_clicked()
{
    QVector<UserModel> users = provider->getAllUsers();
    newUserSettingsDialog = new userSettingsDialog(users);
    newUserSettingsDialog->show();
    connect(newUserSettingsDialog, &userSettingsDialog::updateUserInfo, this, &VehicleDashboard::updateUser);
    connect(newUserSettingsDialog, &userSettingsDialog::addUserToDb, this, &VehicleDashboard::addUserSlot);
    connect(this, &VehicleDashboard::updateDetails ,newUserSettingsDialog, &userSettingsDialog::renderUserComboBox);

}

void VehicleDashboard::addUserSlot(const QString& userName){
    provider->addUser(userName);
}

void VehicleDashboard::updateUser(UserModel user){
    provider->updateUser(user);
}
