#include "fluidmodel.h"

FluidModel::FluidModel() {}

QList<QString> FluidModel::getFluidList(){
    return fluidList;
}

QList<QString> FluidModel::setFluidList(QString newFluid){
    if(!fluidList.contains(newFluid)){
        fluidList.append(newFluid);
    }
    return fluidList;
}
