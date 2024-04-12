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

    bool isUpdated = db->addUser(userName);
    // qDebug() << "jwekenkwenk"<<isUpdated;

    if(!isUpdated) {
        emit usersUpdated();
        return true;
    }
    return false;
}

UserModel dataprovider::getUser(const QString &userName)
{
    // if (userName.trimmed().isEmpty())
    //     return QVariantMap();

    return db->getUser(userName);
}

bool dataprovider::updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours)
{

    if (userName.trimmed().isEmpty() || totalKms < 0 || batteryLevel < 0 || engineHours < 0)
        return false;

    return db->updateVehicleInfo(userName, totalKms, batteryLevel, engineHours);
}

VehicleInfo dataprovider::getVehicleInfo()
{
    return db->getVehicleInfo();
}

QVector<UserModel>dataprovider::getAllUsers(){
    return db->getAllUsers();
};

bool dataprovider::updateUser(const UserModel& userModel){

    bool isUpdated = db->updateUser(userModel);
    // qDebug() << "jwekenkwenk"<<isUpdated;

    if(isUpdated) {
        emit usersUpdated();
        return true;
    }
    return false;
};
