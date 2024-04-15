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


    batteryLevel = currentUser.getBatteryLevel();
    engineHours = currentUser.getEngineHours();
    fuelLeft = currentUser.getFuelLeft();

    qDebug() << "currentUser.getTotalKms()" <<currentUser.getTotalKms();

    ui->distanceLabel->setDigitCount(3);
    ui->distanceLabel->display(currentUser.getTotalKms());

    ui->batteryLabel->setDigitCount(3);
    ui->batteryLabel->display(currentUser.getBatteryLevel());

    ui->engineHours->setDigitCount(3);
    ui->engineHours->display(engineHours);

    ui->progressBar->setValue(fuelLeft);


    increaseSpeedTimer = new QTimer;
    increaseSpeedTimer->setSingleShot(false);
    increaseSpeedTimer->setInterval(100);
    updateColor(currentUser.getUserColor());

    if(currentUser.getUserMode() == "Sport") RPM = 6000;

    connect(increaseSpeedTimer, &QTimer::timeout, this, &VehicleInstrumentPanel::increaseSpeed);

    if(batteryLevel > 0 || fuelLeft > 0) increaseSpeedTimer->start();
    else{
        QMessageBox::critical(nullptr,"Alert", "Not Enough battery or fuel, please charge the vehicle.");
    }

}

void VehicleInstrumentPanel::updateColor(QString color){
    if (colorMap.contains(color)) {
        QString hexCode = colorMap[color];
        QString styleSheet = QString("background-color: %1;").arg(hexCode);
        this->setStyleSheet(styleSheet);
    } else {
        this->setStyleSheet("background-color: rgb(184, 193, 236);");
        qDebug() << "Invalid color name: " << color;
    }
}

void VehicleInstrumentPanel::increaseSpeed(){
    if(speed >= 300){
        QMessageBox::critical(nullptr,"Alert", "Speed Limit Exceeded, Slowing Down");
        increaseSpeedTimer->stop();
    }

    totalMsPassed += 100;
    int offset = 1000;

    if(fuelLeft>0 and batteryLevel >0 and (totalMsPassed % 10000) == 0){
        // batteryLevel -= static_cast<int>(((totalMsPassed*RPM)/10000)/(offset));
        batteryLevel--;
        ui->batteryLabel->setDigitCount(3);
        ui->batteryLabel->display(batteryLevel);
        ui->progressBar->setValue(fuelLeft);
        engineHours += 1;
        ui->engineHours->display(engineHours);
        fuelLeft--;
    }


    if(batteryLevel < 1){
        increaseSpeedTimer->stop();
        QMessageBox::critical(nullptr,"Alert", "Not Enough battery, please charge the vehicle.");
    }

    if(totalMsPassed % 20000 == 0){
        engineHours++;
    }

    int distanceTravelled =(RPM*speed)/63360;
    ui->distanceLabel->display(currentUser.getTotalKms() + distanceTravelled);


    speed++;

    ui->dial->setValue(speed);
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->display(speed);
}

void VehicleInstrumentPanel::closeEvent(QCloseEvent *event)
{
    emit closeButtonClicked();
    increaseSpeedTimer->stop();
    distanceTravelled =(RPM*speed)/63360;
    QWidget::closeEvent(event);
    speed = 0;
    emit updateLastUserDetails(currentUser.getUserName(), currentUser.getTotalKms() + distanceTravelled, batteryLevel, engineHours, fuelLeft);
}

void VehicleInstrumentPanel::updateUI(UserModel user){
    updateColor(user.getColor());
}

void VehicleInstrumentPanel::getValues(){
    emit updateLastUserValues(distanceTravelled, batteryLevel, 45, fuelLeft);
}

VehicleInstrumentPanel::~VehicleInstrumentPanel()
{
    delete ui;
    delete increaseSpeedTimer;

}

void VehicleInstrumentPanel::on_pushButton_clicked()
{
    leftIndicatorOn = !rightIndicatorOn ? true : false;
    if(!isIndicatorOn || leftIndicatorOn)
    {
        isIndicatorOn = true;
        blinkTimer = new QTimer(this);
        blinkTimer->setInterval(500);
        connect(blinkTimer, &QTimer::timeout, this, &VehicleInstrumentPanel::toggleImageVisibility);
        blinkTimer->start();
    }
}

void VehicleInstrumentPanel::on_pushButton_2_clicked()
{
    rightIndicatorOn = !leftIndicatorOn ? true : false;;
    if(!isIndicatorOn || rightIndicatorOn)
    {
        isIndicatorOn = true;
        blinkTimer = new QTimer(this);
        blinkTimer->setInterval(500);
        connect(blinkTimer, &QTimer::timeout, this, &VehicleInstrumentPanel::toggleImageVisibility);
        blinkTimer->start();
    }
}


void VehicleInstrumentPanel::toggleImageVisibility(){
    if(leftIndicatorOn) ui->leftIndicatorLabel->setPixmap( ui->leftIndicatorLabel->pixmap().isNull() ? leftIndicator : QPixmap());

    if(rightIndicatorOn) ui->rightIndicatorLabel->setPixmap( ui->rightIndicatorLabel->pixmap().isNull() ? rightIndicator : QPixmap());

    if(blinkcount == 8){
        if(leftIndicatorOn){
         ui->leftIndicatorLabel->setPixmap(leftIndicator);
         leftIndicatorOn = false;
        }else{
         ui->rightIndicatorLabel->setPixmap(rightIndicator);
         rightIndicatorOn = false;
        }
         blinkTimer->stop();
         isIndicatorOn = false;
         blinkcount = 0;
    }

    blinkcount++;
}

void VehicleInstrumentPanel::handleReset(){
    ui->distanceLabel->setDigitCount(3);
    ui->distanceLabel->display(0);

    ui->batteryLabel->setDigitCount(3);
    ui->batteryLabel->display(100);

    ui->engineHours->setDigitCount(3);
    ui->engineHours->display(0);

    ui->progressBar->setValue(100);

}

