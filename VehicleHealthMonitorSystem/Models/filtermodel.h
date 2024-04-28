#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <QObject>
#include <QDebug>

class FilterModel:public QObject
{
    Q_OBJECT
public:
    FilterModel(QString name, int healthLevel=100);
    static QList<FilterModel> getFilterList();
    FilterModel(const FilterModel& other);
    FilterModel& operator=(const FilterModel& other);

    FilterModel setFilterHealth(int num);
    QString getFilterName() const;
    int getFilterHealth() const;
    static QList<FilterModel> addFilterToList(const FilterModel& newFilter);
    static QList<FilterModel > filterList;

private:
    int healthLevel;
    QString name;
};

#endif // FILTERMODEL_H
