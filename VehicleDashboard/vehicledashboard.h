#ifndef VEHICLEDASHBOARD_H
#define VEHICLEDASHBOARD_H

#include <QMainWindow>
#include <QTimer>
#include "dataprovider.h"
#include "usersettingsdialog.h"
#include "vehicleinstrumentpanel.h"

#include "models/userModel.h"
#include "models/vehicleInfoModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VehicleDashboard; }
QT_END_NAMESPACE

class VehicleDashboard : public QMainWindow
{
    Q_OBJECT

public:
    VehicleDashboard(QWidget *parent = nullptr);
    ~VehicleDashboard();

private slots:
    void on_startButton_clicked();
    void addUserSlot(const QString& userName);
    void on_userSettingsButton_clicked();
    void handleUpdates();
    void updateUser(UserModel user);

private:
    int batteryLevel;
    int totalDistanceTravelled;
    Ui::VehicleDashboard *ui;
    dataprovider *provider;
    QTimer *vehicleStartedTimer;
    void handleTimeout();
    bool isVehicleStarted = false;
    userSettingsDialog *newUserSettingsDialog;
    VehicleInstrumentPanel *newVehicleInstrumentPanel = nullptr;
    VehicleInfo* previousInfo;

signals:
    void updateDetails(QVector<UserModel> users);

};
#endif // VEHICLEDASHBOARD_H
