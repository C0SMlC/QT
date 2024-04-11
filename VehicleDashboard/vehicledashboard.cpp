#include "vehicledashboard.h"
#include "./ui_vehicledashboard.h"

VehicleDashboard::VehicleDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehicleDashboard),
    provider(new dataprovider)

{
    ui->setupUi(this);
    this->setWindowTitle("Start Menu");

    QVariantMap vehicleInfo = provider->getVehicleInfo();

    if (!vehicleInfo.isEmpty()) {

        qDebug() << "Vehicle Information:";
        qDebug() << "User Name:" << vehicleInfo["user_name"];
        qDebug() << "Total Kms:" << vehicleInfo["totalKms"].toLongLong();
        qDebug() << "Battery Level:" << vehicleInfo["batteryLevel"];
        qDebug() << "Engine Hours:" << vehicleInfo["engineHours"];
        qDebug() << "User ID:" << vehicleInfo["userId"];
        qDebug() << "User Mode:" << vehicleInfo["userMode"];
        qDebug() << "User Color:" << vehicleInfo["userColor"];
        qDebug() << "User Distance:" << vehicleInfo["userDistance"];
    } else {
        qDebug() << "No vehicle information found.";
    }

    vehicleStartedTimer = new QTimer;
    vehicleStartedTimer->setSingleShot(false);
    vehicleStartedTimer->setInterval(5000);

    connect(vehicleStartedTimer, &QTimer::timeout, this, &VehicleDashboard::handleTimeout);

//    vehicleStartedTimer->start();
}

void VehicleDashboard::handleTimeout(){

    if(batteryLevel > 0) batteryLevel--;
    qDebug() << "Battery level decreased, Battery Level Is,"<<batteryLevel;
}

VehicleDashboard::~VehicleDashboard()
{
//    provider->updateBatteryLevel(batteryLevel);
//    provider->updateTotalDistanceTravelled(totalDistanceTravelled);

    delete provider;
    delete vehicleStartedTimer;
    delete ui;
}


void VehicleDashboard::on_startButton_clicked()
{
    if(!newVehicleInstrumentPanel){
        newVehicleInstrumentPanel = new VehicleInstrumentPanel;
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
    newUserSettingsDialog = new userSettingsDialog;
    newUserSettingsDialog->show();
}
