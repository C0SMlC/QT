#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include "../models/userModel.h"
#include "../models/vehicleInfoModel.h"

class database : public QObject {
    Q_OBJECT

private:
    database() {}
    database(const database&) = delete;
    database& operator=(const database&) = delete;
    UserModel* user;
    VehicleInfo* vehicle;

public:
    static database* getInstance();
    bool createTable();
    bool addUser(const QString &userName);
    UserModel getUser(const QString &userName);
    VehicleInfo getVehicleInfo();
    bool updateUser(const UserModel& userModel);
    bool updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours, int fuelLeft);
    bool updateLastUserWithoutStart(QString username);
    QVector<UserModel> getAllUsers();
};

#endif // DATABASE_H
