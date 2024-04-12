#include "vehicleinstrumentpanel.h"
#include "ui_vehicleinstrumentpanel.h"

QMap<QString, QString> colorMap = {
    {"Red", "#ff0000"},
    {"Blue", "#0000ff"},
    {"Green", "#00ff00"},
    {"Yellow", "#ffff00"},
    {"Black", "#000000"},
    {"White", "#ffffff"}
};
VehicleInstrumentPanel::VehicleInstrumentPanel(VehicleInfo currentUser, QWidget *parent) :
    QWidget(parent),
    currentUser(currentUser),
    ui(new Ui::VehicleInstrumentPanel)
{
    ui->setupUi(this);

    increaseSpeedTimer = new QTimer;
    increaseSpeedTimer->setSingleShot(false);
    increaseSpeedTimer->setInterval(100);

    if (colorMap.contains(currentUser.getUserColor())) {
        QString hexCode = colorMap[currentUser.getUserColor()];
        QString styleSheet = QString("background-color: %1;").arg(hexCode);
        qDebug() << styleSheet;
        this->setStyleSheet(styleSheet);
    } else {
        this->setStyleSheet("background-color: rgb(184, 193, 236);");
        qDebug() << "Invalid color name: " << currentUser.getUserColor();
    }

    qDebug() << "Vehicle Information:";
    qDebug() << "User Name:" << currentUser.getUserName();
    qDebug() << "Total Kms:" << currentUser.getTotalKms();
    qDebug() << "Battery Level:" << currentUser.getEngineHours();
    qDebug() << "Engine Hours:" << currentUser.getBatteryLevel();
    qDebug() << "User ID:" << currentUser.getUserId();
    qDebug() << "User Mode:" << currentUser.getUserMode();
    qDebug() << "User Color:" << currentUser.getUserColor();
    qDebug() << "User Distance:" << currentUser.getUserDistance();


    connect(increaseSpeedTimer, &QTimer::timeout, this, &VehicleInstrumentPanel::increaseSpeed);

    increaseSpeedTimer->start();

}

void VehicleInstrumentPanel::increaseSpeed(){
    if(speed >= 300){
        QMessageBox::critical(nullptr,"Alert", "Speed Limit Exceeded, Slowing Down");
        increaseSpeedTimer->stop();
    }

    ui->dial->setValue(speed);

    speed++;
}

VehicleInstrumentPanel::~VehicleInstrumentPanel()
{
    delete ui;
}
