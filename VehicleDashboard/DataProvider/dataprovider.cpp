#include "dataprovider.h"

dataprovider::dataprovider()
    : db(database::instance())
{
}

bool dataprovider::updateTotalDistanceTravelled(int distance) {
    return db.updateTotalDistanceTravelled(distance);
}

bool dataprovider::updateBatteryLevel(int level) {
    return db.updateBatteryLevel(level);
}

bool dataprovider::updateEngineHours(int hours) {
    return db.updateEngineHours(hours);
}

bool dataprovider::updateEstimatedFuelRange(int range) {
    return db.updateEstimatedFuelRange(range);
}

int dataprovider::getTotalDistanceTravelled() {
    return db.getTotalDistanceTravelled();
}

int dataprovider::getBatteryLevel() {
    return db.getBatteryLevel();
}

int dataprovider::getEngineHours() {
    return db.getEngineHours();
}

int dataprovider::getEstimatedFuelRange() {
    return db.getEstimatedFuelRange();
}
