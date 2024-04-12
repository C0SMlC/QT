#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>

class UserModel
{
public:
    UserModel();
    UserModel(int id, const QString &userName, const QString &mode, QString color, int distance);
    UserModel(const QString &userName, const QString &mode, const QString &color, int distance);
    int getId() const;
    QString getUserName() const;
    QString getMode() const;
    QString getColor() const;
    int getDistance() const;

    void setId(int id);
    void setUserName(const QString &userName);
    void setMode(const QString &mode);
    void setColor(QString color);
    void setDistance(int distance);

private:
    int id;
    QString userName;
    QString mode;
    QString color;
    int distance;
};

#endif // USERMODEL_H
