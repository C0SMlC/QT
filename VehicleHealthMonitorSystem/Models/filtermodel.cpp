#include "filtermodel.h"

QList<FilterModel> FilterModel::filterList;

FilterModel::FilterModel(QString name, int healthLevel):name(name), healthLevel(healthLevel){

}

QList<FilterModel> FilterModel::getFilterList(){
    return filterList;
}

QString FilterModel::getFilterName() const {
    return this->name;
}

int FilterModel::getFilterHealth() const {
    return this->healthLevel;
}

FilterModel FilterModel::setFilterHealth(int num) {
    if(num > this->healthLevel) this->healthLevel = 0;

    if(this->healthLevel - num > 0) {
        this->healthLevel =  this->healthLevel - num;
    }
    return *this;
}

QList<FilterModel> FilterModel::addFilterToList(const FilterModel& newFilter){
    for(const auto& filter: filterList){
        if(filter.name == newFilter.name) return filterList;
    }

    filterList.append(newFilter);
    return filterList;
}

FilterModel::FilterModel(const FilterModel& other)
    :healthLevel(other.healthLevel), name(other.name)
{
}

FilterModel& FilterModel::operator=(const FilterModel& other)
{
    if (this != &other) {
        healthLevel = other.healthLevel;
        name = other.name;
    }
    return *this;
}
