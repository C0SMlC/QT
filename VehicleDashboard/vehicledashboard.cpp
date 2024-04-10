#include "vehicledashboard.h"
#include "./ui_vehicledashboard.h"

VehicleDashboard::VehicleDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehicleDashboard),
    provider(new dataprovider)

{
    ui->setupUi(this);

    batteryLevel = provider->getBatteryLevel() == 0 ? 100 : provider->getBatteryLevel();
    totalDistanceTravelled = provider->getTotalDistanceTravelled();

    vehicleStartedTimer = new QTimer;
    vehicleStartedTimer->setSingleShot(false);
    vehicleStartedTimer->setInterval(5000);

    connect(vehicleStartedTimer, &QTimer::timeout, this, &VehicleDashboard::handleTimeout);

    vehicleStartedTimer->start();
}

void VehicleDashboard::handleTimeout(){
    if(batteryLevel > 0) batteryLevel--;
    qDebug() << "Battery level decreased, Battery Level Is,"<<batteryLevel;
}

VehicleDashboard::~VehicleDashboard()
{
    provider->updateBatteryLevel(batteryLevel);
    provider->updateTotalDistanceTravelled(totalDistanceTravelled);

    delete provider;
    delete vehicleStartedTimer;
    delete ui;
}

