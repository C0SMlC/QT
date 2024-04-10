#include "database.h"

database& database::instance() {
    static database _instance;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VehicleDashboard.db");

    if (db.open()) {
        _instance.createTable();

    } else {
        qDebug() << "Error in adding the databse.\n";
    }

    return _instance;
}


bool database::createTable()
{
    QSqlQuery query("CREATE TABLE IF NOT EXISTS VehicleDashboard (id INTEGER PRIMARY KEY AUTOINCREMENT, totalDistanceTravelled INT, batteryLevel INT, engineHours INT, estimatedFuelRange INT)");
    if(query.exec()){
      qDebug() <<"Table Created Successfully";
    }
    return query.exec();
}

bool database::updateTotalDistanceTravelled(int distance) {
    QSqlQuery query;
    query.prepare("UPDATE VehicleDashboard SET totalDistanceTravelled = totalDistanceTravelled + :totalDistanceTravelled");
    query.bindValue(":totalDistanceTravelled", distance);

    if (!query.exec()) {
      qDebug() << "Error updating totalDistanceTravelled:" << query.lastError().text();
      return false;
    }

    qDebug() << "Total distance travelled updated successfully.";
    return true;
}

bool database::updateBatteryLevel(int level) {
    QSqlQuery query;
    query.prepare("UPDATE VehicleDashboard SET batteryLevel = batteryLevel + :batteryLevel");
    query.bindValue(":batteryLevel", level);

    if (!query.exec()) {
      qDebug() << "Error updating batteryLevel:" << query.lastError().text();
      return false;
    }

    qDebug() << "Battery level updated successfully.";
    return true;
}

bool database::updateEngineHours(int hours) {
    QSqlQuery query;
    query.prepare("UPDATE VehicleDashboard SET engineHours = :engineHours");
    query.bindValue(":engineHours", hours);

    if (!query.exec()) {
      qDebug() << "Error updating engineHours:" << query.lastError().text();
      return false;
    }

    qDebug() << "Engine hours updated successfully.";
    return true;
}

bool database::updateEstimatedFuelRange(int range) {
    QSqlQuery query;
    query.prepare("UPDATE VehicleDashboard SET estimatedFuelRange = :estimatedFuelRange");
    query.bindValue(":estimatedFuelRange", range);

    if (!query.exec()) {
      qDebug() << "Error updating estimatedFuelRange:" << query.lastError().text();
      return false;
    }

    qDebug() << "Estimated fuel range updated successfully.";
    return true;
}

int database::getTotalDistanceTravelled() {
    QSqlQuery query("SELECT totalDistanceTravelled FROM VehicleDashboard");
    if (query.exec() && query.next()) {
      return query.value(0).toInt();
    } else {
      qDebug() << "Error retrieving totalDistanceTravelled:" << query.lastError().text();
      return 0;
    }
}

int database::getBatteryLevel() {
    QSqlQuery query("SELECT batteryLevel FROM VehicleDashboard");
    if (query.exec() && query.next()) {
      return query.value(0).toInt();
    } else {
      qDebug() << "Error retrieving batteryLevel:" << query.lastError().text();
      return 0;
    }
}

int database::getEngineHours() {
    QSqlQuery query("SELECT engineHours FROM VehicleDashboard");
    if (query.exec() && query.next()) {
      return query.value(0).toInt();
    } else {
      qDebug() << "Error retrieving engineHours:" << query.lastError().text();
      return 0;
    }
}

int database::getEstimatedFuelRange() {
    QSqlQuery query("SELECT estimatedFuelRange FROM VehicleDashboard");
    if (query.exec() && query.next()) {
      return query.value(0).toInt();
    } else {
      qDebug() << "Error retrieving estimatedFuelRange:" << query.lastError().text();
      return 0;
    }
}
