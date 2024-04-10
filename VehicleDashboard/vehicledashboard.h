#ifndef VEHICLEDASHBOARD_H
#define VEHICLEDASHBOARD_H

#include <QMainWindow>
#include <QTimer>
#include "dataprovider.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VehicleDashboard; }
QT_END_NAMESPACE

class VehicleDashboard : public QMainWindow
{
    Q_OBJECT

public:
    VehicleDashboard(QWidget *parent = nullptr);
    ~VehicleDashboard();

private:
    int batteryLevel;
    int totalDistanceTravelled;
    Ui::VehicleDashboard *ui;
    dataprovider *provider;
    QTimer *vehicleStartedTimer;
    void handleTimeout();

};
#endif // VEHICLEDASHBOARD_H
