#include "fluidmodel.h"

QList<FluidModel> FluidModel::fluidList;

FluidModel::FluidModel(QString name, int healthLevel):name(name), healthLevel(healthLevel){

}

QList<FluidModel> FluidModel::getFluidList(){
    return fluidList;
}

QString FluidModel::getFluidName() const {
    return this->name;
}

int FluidModel::getFluidHealth() const {
    return this->healthLevel;
}

FluidModel FluidModel::setFluidHealth(int num) {
    if(this->healthLevel - num > 0) {
        this->healthLevel =  this->healthLevel - num;
    }

    qDebug() << this->healthLevel;
    return *this;
}

QList<FluidModel> FluidModel::addFluidToList(const FluidModel& newFilter){
    for(const auto& filter: fluidList){
        if(filter.name == newFilter.name) return fluidList;
    }

    fluidList.append(newFilter);
    return fluidList;
}

FluidModel::FluidModel(const FluidModel& other)
    :healthLevel(other.healthLevel), name(other.name)
{
}

FluidModel& FluidModel::operator=(const FluidModel& other)
{
    if (this != &other) {
        healthLevel = other.healthLevel;
        name = other.name;
    }
    return *this;
}
