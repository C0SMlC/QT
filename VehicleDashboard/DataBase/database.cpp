#include "database.h"

database* database::getInstance() {
     database* _instance = new database;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("VehicleDashboard.db");

    if (db.open()) {
        _instance->createTable();

    } else {
        qDebug() << "Error in adding the databse.\n";
    }

    return _instance;
}


bool database::createTable()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS user ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "user_name TEXT, "
                    "mode TEXT, "
                    "color INT, "
                    "distance INT)"))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "User Table Created Successfully";

    if (!query.exec("CREATE TABLE IF NOT EXISTS vehicleInfo ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "user_name TEXT UNIQUE, "
                    "totalKms INT, "
                    "batteryLevel INT, "
                    "engineHours INT, "
                    "FOREIGN KEY (user_name) REFERENCES user (user_name))"))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "Vehicle Info Table Created Successfully";

    return true;
}

bool database::addUser(const QString &userName) {
    QSqlQuery query;
    query.prepare("INSERT INTO user(user_name, mode, color, distance) VALUES (:user_name, :mode, :color, :distance)");
    query.bindValue(":user_name", userName);
    query.bindValue(":mode", "default");
    query.bindValue(":color", "default");
    query.bindValue(":distance", 0);
    return query.exec();
}

QVariantMap database::getUser(const QString &userName) {
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE user_name = :userName");
    query.bindValue(":userName", userName);
    query.exec();

    QVariantMap userInfo;
    if (query.next()) {
        userInfo["id"] = query.value("id");
        userInfo["mode"] = query.value("mode");
        userInfo["color"] = query.value("color");
        userInfo["distance"] = query.value("distance");
    }

    return userInfo;
}

bool database::updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours) {
    QSqlQuery query;
    query.prepare("UPDATE vehicleInfo "
                  "SET totalKms = :totalKms, batteryLevel = :batteryLevel, engineHours = :engineHours "
                  "WHERE user_name = :user_name");
    query.bindValue(":user_name", userName);
    query.bindValue(":totalKms", totalKms);
    query.bindValue(":batteryLevel", batteryLevel);
    query.bindValue(":engineHours", engineHours);
    return query.exec();
}


QVariantMap database::getVehicleInfo() {
    QSqlQuery query;
    query.prepare("SELECT v.*, u.* "
                  "FROM vehicleInfo v "
                  "JOIN user u ON v.user_name = u.user_name "
                  );
    query.exec();

    QVariantMap vehicleInfo;
    if (query.next()) {
        vehicleInfo["id"] = query.value("id");
        vehicleInfo["user_name"] = query.value("user_name");
        vehicleInfo["totalKms"] = query.value("totalKms");
        vehicleInfo["batteryLevel"] = query.value("batteryLevel");
        vehicleInfo["engineHours"] = query.value("engineHours");
        vehicleInfo["userId"] = query.value("id");
        vehicleInfo["userMode"] = query.value("mode");
        vehicleInfo["userColor"] = query.value("color");
        vehicleInfo["userDistance"] = query.value("distance");
    }

    return vehicleInfo;
}




//bool database::updateTotalDistanceTravelled(int distance) {
//    QSqlQuery query;
//    query.prepare("UPDATE VehicleDashboard SET totalDistanceTravelled = totalDistanceTravelled + :totalDistanceTravelled");
//    query.bindValue(":totalDistanceTravelled", distance);

//    if (!query.exec()) {
//      qDebug() << "Error updating totalDistanceTravelled:" << query.lastError().text();
//      return false;
//    }

//    qDebug() << "Total distance travelled updated successfully.";
//    return true;
//}

//bool database::updateBatteryLevel(int level) {
//    QSqlQuery query;
//    query.prepare("UPDATE VehicleDashboard SET batteryLevel = batteryLevel + :batteryLevel");
//    query.bindValue(":batteryLevel", level);

//    if (!query.exec()) {
//      qDebug() << "Error updating batteryLevel:" << query.lastError().text();
//      return false;
//    }

//    qDebug() << "Battery level updated successfully.";
//    return true;
//}

//bool database::updateEngineHours(int hours) {
//    QSqlQuery query;
//    query.prepare("UPDATE VehicleDashboard SET engineHours = :engineHours");
//    query.bindValue(":engineHours", hours);

//    if (!query.exec()) {
//      qDebug() << "Error updating engineHours:" << query.lastError().text();
//      return false;
//    }

//    qDebug() << "Engine hours updated successfully.";
//    return true;
//}

//bool database::updateEstimatedFuelRange(int range) {
//    QSqlQuery query;
//    query.prepare("UPDATE VehicleDashboard SET estimatedFuelRange = :estimatedFuelRange");
//    query.bindValue(":estimatedFuelRange", range);

//    if (!query.exec()) {
//      qDebug() << "Error updating estimatedFuelRange:" << query.lastError().text();
//      return false;
//    }

//    qDebug() << "Estimated fuel range updated successfully.";
//    return true;
//}

//int database::getTotalDistanceTravelled() {
//    QSqlQuery query("SELECT totalDistanceTravelled FROM VehicleDashboard");
//    if (query.exec() && query.next()) {
//      return query.value(0).toInt();
//    } else {
//      qDebug() << "Error retrieving totalDistanceTravelled:" << query.lastError().text();
//      return 0;
//    }
//}

//int database::getBatteryLevel() {
//    QSqlQuery query("SELECT batteryLevel FROM VehicleDashboard");
//    if (query.exec() && query.next()) {
//      return query.value(0).toInt();
//    } else {
//      qDebug() << "Error retrieving batteryLevel:" << query.lastError().text();
//      return 0;
//    }
//}

//int database::getEngineHours() {
//    QSqlQuery query("SELECT engineHours FROM VehicleDashboard");
//    if (query.exec() && query.next()) {
//      return query.value(0).toInt();
//    } else {
//      qDebug() << "Error retrieving engineHours:" << query.lastError().text();
//      return 0;
//    }
//}

//int database::getEstimatedFuelRange() {
//    QSqlQuery query("SELECT estimatedFuelRange FROM VehicleDashboard");
//    if (query.exec() && query.next()) {
//      return query.value(0).toInt();
//    } else {
//      qDebug() << "Error retrieving estimatedFuelRange:" << query.lastError().text();
//      return 0;
//    }
//}
