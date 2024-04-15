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
    delete newVehicleInstrumentPanel;
    delete ui;
}


void VehicleDashboard::on_startButton_clicked()
{
    if(!newVehicleInstrumentPanel || !isVehicleStarted){
        VehicleInfo previosusInfo = provider->getVehicleInfo();
        newVehicleInstrumentPanel = new VehicleInstrumentPanel(previosusInfo);
        newVehicleInstrumentPanel->show();
        connect(this, &VehicleDashboard::updateInstrumentalPanel, newVehicleInstrumentPanel, &VehicleInstrumentPanel::updateUI);
        connect(this, &VehicleDashboard::updateResetValues, newVehicleInstrumentPanel, &VehicleInstrumentPanel::handleReset);
        connect(newVehicleInstrumentPanel, &VehicleInstrumentPanel::updateLastUserDetails, this, &VehicleDashboard::updateLastUser);
        connect(this, &VehicleDashboard::getTotalValuesAndUpdateDB, newVehicleInstrumentPanel, &VehicleInstrumentPanel::getValues);
        connect(newVehicleInstrumentPanel, &VehicleInstrumentPanel::updateLastUserValues, this,  &VehicleDashboard::updateLastUserDetails);
        connect(newVehicleInstrumentPanel, &VehicleInstrumentPanel::closeButtonClicked, this, &VehicleDashboard::onVehicleInstrumentPanelClosed);
    }

    if(!isVehicleStarted){
        ui->startButton->setStyleSheet("Background-color: '#078080'; border-radius:62px;");
        ui->startButton->setText("Stop");
        isVehicleStarted = true;
    }else{
        ui->startButton->setStyleSheet("Background-color: '#f45d48'; border-radius:62px;");
        ui->startButton->setText("Start");
        isVehicleStarted = false;
        delete newVehicleInstrumentPanel;
    }
}

void VehicleDashboard::onVehicleInstrumentPanelClosed(){
    if(!newVehicleInstrumentPanel) delete newVehicleInstrumentPanel;
    ui->startButton->setStyleSheet("Background-color: '#f45d48'; border-radius:62px;");
    ui->startButton->setText("Start");
    isVehicleStarted = false;
    emit getTotalValuesAndUpdateDB();
}

void VehicleDashboard::on_userSettingsButton_clicked()
{
    QVector<UserModel> users = provider->getAllUsers();

    newUserSettingsDialog = new userSettingsDialog(provider->getVehicleInfo(), users);
    newUserSettingsDialog->show();
    connect(newUserSettingsDialog, &userSettingsDialog::updateUserInfo, this, &VehicleDashboard::updateUser);
    connect(newUserSettingsDialog, &userSettingsDialog::addUserToDb, this, &VehicleDashboard::addUserSlot);
    connect(this, &VehicleDashboard::updateComboBox, newUserSettingsDialog, &userSettingsDialog::renderPreviousValues);
    connect(this, &VehicleDashboard::updateDetails ,newUserSettingsDialog, &userSettingsDialog::renderUserComboBox);

}

void VehicleDashboard::updateLastUser(const QString &userName, int totalKms, int batteryLevel, int engineHours, int fuelLeft){
    provider->updateVehicleInfo(userName, totalKms, batteryLevel, engineHours, fuelLeft);
}

void VehicleDashboard::addUserSlot(const QString& userName){
    provider->addUser(userName);
}

void VehicleDashboard::updateUser(UserModel user){
    provider->updateUser(user);

    if(isVehicleStarted){
        emit updateInstrumentalPanel(user);
    }else{
        this->updateLastUserWithoutStart(user.getUserName());
    }

    lastUserName = user.getUserName();

    emit getTotalValuesAndUpdateDB();
}

void VehicleDashboard::updateLastUserWithoutStart(QString username){
    provider->updateLastUserWithoutStart(username);
}

void VehicleDashboard::updateLastUserDetails(int distanceTravelled,int batteryLevel, int engineHours, int fuelLeft){
    provider->updateVehicleInfo(lastUserName, totalDistanceTravelled, batteryLevel, engineHours, fuelLeft);
    emit updateComboBox(provider->getVehicleInfo());
}

void VehicleDashboard::on_pushButton_3_clicked()
{
    provider->updateVehicleInfo(provider->getVehicleInfo().getUserName(),0,100,0, 100);

    if(newVehicleInstrumentPanel != nullptr) emit updateResetValues();
}

