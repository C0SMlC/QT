#ifndef DEVICEDETAILS_H
#define DEVICEDETAILS_H

#include <vector>
#include <iostream>
#include <QDebug>


class DeviceDetails{

public:
    DeviceDetails(){};
    DeviceDetails(std::string deviceName, std::string deviceSerialNumber, std::string fileName, std::string assignee, std::string location );
    static void insertLog(const DeviceDetails& newLog);
    void printLogs();

    std::string getDeviceName() const;         // Mark as 'const' for read-only
    std::string getDeviceSerialNumber() const;
    std::string getFileName() const;
    std::string getFileLocation() const;
    std::string getAssignee() const;
    std::string getLocation() const;

private:
    std::string deviceName;
    std::string deviceSerialNumber;
    std::string fileName;
    std::string fileLocation;
    std::string assignee;
    std::string location;
    static std::vector<DeviceDetails> deviceDetailsLogs;

};

#endif // DEVICEDETAILS_H
