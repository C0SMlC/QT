#include "vehicleinstrumentpanel.h"
#include "ui_vehicleinstrumentpanel.h"

VehicleInstrumentPanel::VehicleInstrumentPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleInstrumentPanel)
{
    ui->setupUi(this);

    increaseSpeedTimer = new QTimer;
    increaseSpeedTimer->setSingleShot(false);
    increaseSpeedTimer->setInterval(2000);

    connect(increaseSpeedTimer, &QTimer::timeout, this, &VehicleInstrumentPanel::increaseSpeed);

    increaseSpeedTimer->start();

}

void VehicleInstrumentPanel::increaseSpeed(){
    if(speed >= 300){
        QMessageBox::critical(nullptr,"Alert", "Speed Limit Exceeded, Slowing Down");
    }

    ui->dial->setValue(speed);
    qDebug() << "Speed: "<<speed;
    speed = speed + 20;


}

VehicleInstrumentPanel::~VehicleInstrumentPanel()
{
    delete ui;
}
