#include "filtermodel.h"

FilterModel::FilterModel() {
    filterList = {"Engine Air Filter", "Cabin Air Filter", "Oil Filter", "Fuel Filter"};
}

QList<QString> FilterModel::getFilterList(){
    return filterList;
}

QList<QString> FilterModel::setFilterList(QString newFilter){
    if(!filterList.contains(newFilter)){
        filterList.append(newFilter);
    }
    return filterList;
}
