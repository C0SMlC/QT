#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include "../DataBase/database.h"

class dataprovider : public QObject
{
    Q_OBJECT

public:
    dataprovider();
    bool updateTotalDistanceTravelled(int distance);
    bool updateBatteryLevel(int level);
    bool updateEngineHours(int hours);
    bool updateEstimatedFuelRange(int range);

    int getTotalDistanceTravelled();
    int getBatteryLevel();
    int getEngineHours();
    int getEstimatedFuelRange();

private:
    database& db;
};

#endif // DATAPROVIDER_H
