#ifndef VEHICLEINSTRUMENTPANEL_H
#define VEHICLEINSTRUMENTPANEL_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include "../models/vehicleInfoModel.h"
#include "../models/userModel.h"

namespace Ui {
class VehicleInstrumentPanel;
}

class VehicleInstrumentPanel : public QWidget
{
    Q_OBJECT

public:
    explicit VehicleInstrumentPanel(VehicleInfo currentUser,QWidget *parent = nullptr);
    void updateColor(QString color);
    void updateUI(UserModel user);
    ~VehicleInstrumentPanel();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QTimer* increaseSpeedTimer;
    Ui::VehicleInstrumentPanel *ui;
    VehicleInfo currentUser;
    int speed = 0;
    double tireCircumferenceInMeter = 2.1;
    double finalDriveRatio = 3.55;
    double gearRatio = 3.36;
    int RPM = 3000;
    int distanceTravelled = 0;
    int batteryLevel;
    int totalMsPassed = 0;
    int engineHours = 0;
    QTimer *blinkTimer;
    QPixmap leftIndicator = QPixmap(":/images/assets/left.png");
    QPixmap rightIndicator = QPixmap(":/images/assets/right.png");
    int blinkcount = 0;
    bool isIndicatorOn = false;
    bool leftIndicatorOn = false;
    bool rightIndicatorOn = false;
    int fuelLeft = 100;

public slots:
    void increaseSpeed();
    void getValues();
    void handleReset();

signals:
    void closeButtonClicked();
    void updateLastUserValues(int distanceTravelled,int batteryLevel, int engineHours, int fuelLeft);
    void updateLastUserDetails(const QString &userName, int totalKms, int batteryLevel, int engineHours, int fuelLeft);
private slots:
    void on_pushButton_clicked();
    void toggleImageVisibility();
    void on_pushButton_2_clicked();

};

#endif // VEHICLEINSTRUMENTPANEL_H
