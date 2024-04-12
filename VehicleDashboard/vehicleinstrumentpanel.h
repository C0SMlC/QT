#ifndef VEHICLEINSTRUMENTPANEL_H
#define VEHICLEINSTRUMENTPANEL_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include "../models/vehicleInfoModel.h"

namespace Ui {
class VehicleInstrumentPanel;
}

class VehicleInstrumentPanel : public QWidget
{
    Q_OBJECT

public:
    explicit VehicleInstrumentPanel(VehicleInfo currentUser,QWidget *parent = nullptr);
    ~VehicleInstrumentPanel();

private:
    QTimer* increaseSpeedTimer;
    Ui::VehicleInstrumentPanel *ui;
    VehicleInfo currentUser;
    int speed = 20;
public slots:
    void increaseSpeed();
};

#endif // VEHICLEINSTRUMENTPANEL_H
