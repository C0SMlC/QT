#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include <QString>

class VehicleInfo {
public:
    VehicleInfo(int id, const QString &userName, int totalKms, int batteryLevel, int fuelLeft,
                int engineHours, int userId, const QString &userMode,
                QString userColor, int userDistance);

    int getId() const;
    const QString &getUserName() const;
    int getTotalKms() const;
    int getBatteryLevel() const;
    int getEngineHours() const;
    int getUserId() const;
    const QString &getUserMode() const;
    QString getUserColor() const;
    int getUserDistance() const;
    int getFuelLeft() const;

// private:
    int id;
    QString userName;
    int totalKms;
    int batteryLevel;
    int engineHours;
    int userId;
    QString userMode;
    QString userColor;
    int userDistance;
    int fuelLeft;
};

#endif // VEHICLEINFO_H
