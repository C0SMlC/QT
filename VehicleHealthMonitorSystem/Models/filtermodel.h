#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <QObject>

class FilterModel:public QObject
{
    Q_OBJECT
public:
    FilterModel();
    QList<QString> getFilterList();
    QList<QString> setFilterList(QString newFilter);

private:
    QList<QString> filterList;
};

#endif // FILTERMODEL_H
