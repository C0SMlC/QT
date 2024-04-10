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
    static database& instance();
    bool createTable();
    bool updateTotalDistanceTravelled(int distance);
    bool updateBatteryLevel(int level);
    bool updateEngineHours(int hours);
    bool updateEstimatedFuelRange(int range);

    int getTotalDistanceTravelled();
    int getBatteryLevel();
    int getEngineHours();
    int getEstimatedFuelRange();
};

#endif // DATABASE_H
