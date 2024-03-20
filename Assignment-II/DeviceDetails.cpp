#include "DeviceDetails.h"

DeviceDetails::DeviceDetails(std::string deviceName, std::string deviceSerialNumber, std::string fileName, std::string assignee, std::string location) :
    deviceName(deviceName),
    deviceSerialNumber(deviceSerialNumber),
    fileName(fileName),
    assignee(assignee),
    location(location)
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

void DeviceDetails::printLogs() {
    if (deviceDetailsLogs.empty()) {
        qDebug() << "No logs recorded yet.";
        return;
    }

    // Print header
    qDebug() << "Device Details Logs:";
    qDebug() << "---------------------";

    for (const DeviceDetails& logEntry : deviceDetailsLogs) {
        qDebug() << "Device Name:" << logEntry.getDeviceName();
        qDebug() << "Serial Number:" << logEntry.getDeviceSerialNumber();
        qDebug() << "File Name:" << logEntry.getFileName();
        qDebug() << "File Location:" << logEntry.getFileLocation();
        qDebug() << "Assignee:" << logEntry.getAssignee();
        qDebug() << "Location:" << logEntry.getLocation();
        qDebug() << "---------------------"; // Separator between entries
    }
}

std::vector<DeviceDetails> DeviceDetails::deviceDetailsLogs;

// Implementation of insertLog
void DeviceDetails::insertLog(const DeviceDetails& newLog) {
    deviceDetailsLogs.push_back(newLog);
}
