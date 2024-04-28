#ifndef FLUIDMODEL_H
#define FLUIDMODEL_H

#include <QObject>
#include <QDebug>

class FluidModel: public QObject
{
    Q_OBJECT
public:
    FluidModel(QString name, int healthLevel=100);
    FluidModel(const FluidModel& other);
    FluidModel& operator=(const FluidModel& other);

    FluidModel setFluidHealth(int num);
    QString getFluidName() const;
    int getFluidHealth() const;

    static QList<FluidModel> getFluidList();
    static QList<FluidModel> addFluidToList(const FluidModel& newFluid);
    static QList<FluidModel > fluidList;

private:
    int healthLevel;
    QString name;
};

#endif // FLUIDMODEL_H
