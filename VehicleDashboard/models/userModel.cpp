#include "userModel.h"


UserModel::UserModel()
{

}

UserModel::UserModel(int id, const QString &userName, const QString &mode, QString color, int distance)
    :
    id(id),
    userName(userName),
    mode(mode),
    color(color),
    distance(distance)
{
}

UserModel::UserModel(const QString &userName, const QString &mode, const QString &color, int distance)
    :
    userName(userName),
    mode(mode),
    color(color),
    distance(distance)
{
}

int UserModel::getId() const {
    return id;
}

QString UserModel::getUserName() const {
    return userName;
}

QString UserModel::getMode() const {
    return mode;
}

QString UserModel::getColor() const {
    return color;
}

int UserModel::getDistance() const {
    return distance;
}


