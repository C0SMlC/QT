#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include "../DataBase/database.h"

class dataprovider : public QObject
{
    Q_OBJECT

public:
    dataprovider();
    bool addUser(const QString &userName);
    UserModel getUser(const QString &userName);
    bool updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours);
    VehicleInfo getVehicleInfo();
    QVector<UserModel> getAllUsers();
    bool updateUser(const UserModel& userModel);

private:
    database* db;

signals:
    void usersUpdated();
};

#endif // DATAPROVIDER_H
