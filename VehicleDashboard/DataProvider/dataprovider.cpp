// dataprovider.cpp
#include "dataprovider.h"

dataprovider::dataprovider()
    : db(database::getInstance())
{
}

bool dataprovider::addUser(const QString &userName)
{
    if (userName.trimmed().isEmpty())
        return false;
    return db->addUser(userName);
}

QVariantMap dataprovider::getUser(const QString &userName)
{
    if (userName.trimmed().isEmpty())
        return QVariantMap();

    return db->getUser(userName);
}

bool dataprovider::updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours)
{

    if (userName.trimmed().isEmpty() || totalKms < 0 || batteryLevel < 0 || engineHours < 0)
        return false;

    return db->updateVehicleInfo(userName, totalKms, batteryLevel, engineHours);
}

QVariantMap dataprovider::getVehicleInfo()
{
    return db->getVehicleInfo();
}
