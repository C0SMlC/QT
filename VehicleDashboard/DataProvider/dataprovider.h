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
    QVariantMap getUser(const QString &userName);
    bool updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours);
    QVariantMap getVehicleInfo();


private:
    database* db;
};

#endif // DATAPROVIDER_H
