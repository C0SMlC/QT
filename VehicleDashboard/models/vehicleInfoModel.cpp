#include "vehicleInfoModel.h"

VehicleInfo::VehicleInfo(int id, const QString &userName, int totalKms, int batteryLevel,
                         int engineHours, int userId, const QString &userMode,
                         QString userColor, int userDistance) :
    id(id),
    userName(userName),
    totalKms(totalKms),
    batteryLevel(batteryLevel),
    engineHours(engineHours),
    userId(userId),
    userMode(userMode),
    userColor(userColor),
    userDistance(userDistance)
{
}

int VehicleInfo::getId() const {
    return id;
}

const QString &VehicleInfo::getUserName() const {
    return userName;
}

int VehicleInfo::getTotalKms() const {
    return totalKms;
}

int VehicleInfo::getBatteryLevel() const {
    return batteryLevel;
}

int VehicleInfo::getEngineHours() const {
    return engineHours;
}

int VehicleInfo::getUserId() const {
    return userId;
}

const QString &VehicleInfo::getUserMode() const {
    return userMode;
}

QString VehicleInfo::getUserColor() const {
    return userColor;
}

int VehicleInfo::getUserDistance() const {
    return userDistance;
}
