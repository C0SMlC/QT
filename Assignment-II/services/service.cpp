#include "service.h"

std::vector<DeviceDetails> DeviceDetails::deviceDetailsLogs;

DeviceDetails::DeviceDetails(std::string deviceName, std::string deviceSerialNumber, std::string fileName, std::string assignee, std::string location) :
    deviceName(deviceName),
    deviceSerialNumber(deviceSerialNumber),
    fileName(fileName),
    assignee(assignee),
    location(location)
{}

DeviceDetails::DeviceDetails(const DeviceDetails& other)
    : deviceName(other.deviceName),
    deviceSerialNumber(other.deviceSerialNumber),
    fileName(other.fileName),
    fileLocation(other.fileLocation),
    assignee(other.assignee),
    location(other.location)
{
}

std::string DeviceDetails::getDeviceName() const {
    return deviceName;
}

std::string DeviceDetails::getDeviceSerialNumber() const {
    return deviceSerialNumber;
}

std::string DeviceDetails::getFileName() const {
    return fileName;
}

std::string DeviceDetails::getFileLocation() const {
    return fileLocation;
}

std::string DeviceDetails::getAssignee() const {
    return assignee;
}

std::string DeviceDetails::getLocation() const {
    return location;
}

void DeviceDetails::printLogs() const {
    if (deviceDetailsLogs.empty()) {
        qDebug() << "No logs recorded yet.";
        return;
    }

    qDebug() << "Device Details Logs:";
    qDebug() << "---------------------";

    for (const DeviceDetails& logEntry : deviceDetailsLogs) {
        qDebug() << "Device Name:" << logEntry.getDeviceName();
        qDebug() << "Serial Number:" << logEntry.getDeviceSerialNumber();
        qDebug() << "File Name:" << logEntry.getFileName();
        qDebug() << "File Location:" << logEntry.getFileLocation();
        qDebug() << "Assignee:" << logEntry.getAssignee();
        qDebug() << "Location:" << logEntry.getLocation();
        qDebug() << "---------------------";
    }
}

void DeviceDetails::insertLogData(const DeviceDetails& newLog){
    this->printLogs();
    DeviceDetails::deviceDetailsLogs.push_back(newLog);
    this->printLogs();
};

