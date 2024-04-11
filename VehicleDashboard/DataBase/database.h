#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class database : public QObject {
    Q_OBJECT

private:
    database() {}
    database(const database&) = delete;
    database& operator=(const database&) = delete;

public:
    static database* getInstance();
    bool createTable();
    bool addUser(const QString &userName);
    QVariantMap getUser(const QString &userName);
    QVariantMap getVehicleInfo();
    bool updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours);
};

#endif // DATABASE_H
