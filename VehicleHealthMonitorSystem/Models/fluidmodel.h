#ifndef FLUIDMODEL_H
#define FLUIDMODEL_H

#include <QObject>

class FluidModel: public QObject
{
    Q_OBJECT
public:
    FluidModel();
    QList<QString> getFluidList();
    QList<QString> setFluidList(QString newFluid);

private:
    QList<QString> fluidList;
};

#endif // FLUIDMODEL_H
