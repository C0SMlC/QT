#include "database.h"

database* database::getInstance() {
     static database* _instance = new database;

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
                    "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "user_name TEXT UNIQUE, "
                    "mode TEXT, "
                    "color TEXT, "
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
                    "fuelLeft INT,"
                    "FOREIGN KEY (user_name) REFERENCES user (user_name))"))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "Vehicle Info Table Created Successfully";

    return true;
}

bool database::updateUser(const UserModel& userModel) {
    QSqlQuery query;
    query.prepare("UPDATE user SET mode = :mode, color = :color, distance = :distance WHERE user_name = :userName");
    query.bindValue(":mode", userModel.getMode());
    query.bindValue(":color", userModel.getColor());
    query.bindValue(":distance", userModel.getDistance());
    query.bindValue(":userName", userModel.getUserName());

    if (!query.exec()) {
        qDebug() << "Error updating user: " << query.lastError().text();
        return false;
    }

    qDebug() << "User updated successfully.";
    return true;
}

bool database::addUser(const QString &userName) {
    QSqlQuery query;

    qDebug() << userName;

    query.prepare("INSERT INTO user(user_name, mode, color, distance) VALUES (:user_name, :mode, :color, :distance)");
    query.bindValue(":user_name", userName);
    query.bindValue(":mode", "default");
    query.bindValue(":color", "default");
    query.bindValue(":distance", 0);

    if(!query.exec()){
        qDebug() <<"Error is "<<query.lastError().text();
    }

    return query.exec();
}

bool database::updateLastUserWithoutStart(QString userName){
    QSqlQuery query;
    query.prepare("UPDATE vehicleInfo "
                  "SET user_name = :user_name "
                  "WHERE id = 1");
    query.bindValue(":user_name", userName);
    return query.exec();
};

UserModel database::getUser(const QString &userName) {
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE user_name = :userName");
    query.bindValue(":userName", userName);
    query.exec();

    QVariantMap userInfo;
    if (query.next()) {
        user = new UserModel(query.value("id").toInt(), query.value("user_name").toString(), query.value("mode").toString(), query.value("color").toString(), query.value("distance").toInt());
    }

    return *user;
}

bool database::updateVehicleInfo(const QString &userName, int totalKms, int batteryLevel, int engineHours, int fuelLeft) {
    QSqlQuery query;
    query.prepare("UPDATE vehicleInfo "
                  "SET totalKms = :totalKms, batteryLevel = :batteryLevel, engineHours = :engineHours, fuelLeft= :fuelLeft "
                  "WHERE user_name = :user_name");
    query.bindValue(":user_name", userName);
    query.bindValue(":totalKms", totalKms);
    query.bindValue(":batteryLevel", batteryLevel);
    query.bindValue(":engineHours", engineHours);
    query.bindValue(":fuelLeft", fuelLeft);
    return query.exec();
}


VehicleInfo database::getVehicleInfo() {
    QSqlQuery query;
    query.prepare("SELECT v.*, u.* "
                  "FROM vehicleInfo v "
                  "JOIN user u ON v.user_name = u.user_name ");
    qDebug()<< query.exec();

     QSqlQuery query2;
    if (!query2.exec("SELECT v.*, u.* FROM vehicleInfo v JOIN user u ON v.user_name = u.user_name ")) {
        qDebug() << "Error executing query: " << query2.lastError();
    }


    if (query.next()) {
         vehicle = new VehicleInfo(
            query.value("id").toInt(),
            query.value("user_name").toString(),
            query.value("totalKms").toInt(),
            query.value("batteryLevel").toInt(),
            query.value("fuelLeft").toInt(),
            query.value("engineHours").toInt(),
            query.value("user_id").toInt(),
            query.value("mode").toString(),
            query.value("color").toString(),
            query.value("distance").toInt()
            );
    }
    return *vehicle;
}

QVector<UserModel> database::getAllUsers() {
    QVector<UserModel> allUsers; // A vector to store the retrieved User objects
    QSqlQuery query;

    if (query.exec("SELECT * FROM user")) {
        while (query.next()) {
            UserModel user(query.value("user_id").toInt(), query.value("user_name").toString(), query.value("mode").toString(), query.value("color").toString(), query.value("distance").toInt());
            allUsers.append(user);
        }
    } else {
        qDebug() << "Error retrieving users: " << query.lastError();
    }

    qDebug() << allUsers.size();

    return allUsers;
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
