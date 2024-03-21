#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>


class DeviceDetails: public QMainWindow
{
public:
    DeviceDetails(){};
    DeviceDetails(std::string deviceName, std::string deviceSerialNumber, std::string fileName, std::string assignee, std::string location );
    DeviceDetails(const DeviceDetails& other);

    std::string getDeviceName() const;
    std::string getDeviceSerialNumber() const;
    std::string getFileName() const;
    std::string getFileLocation() const;
    std::string getAssignee() const;
    std::string getLocation() const;
    void printLogs() const;

private:
    std::string deviceName;
    std::string deviceSerialNumber;
    std::string fileName;
    std::string fileLocation;
    std::string assignee;
    std::string location;
    static std::vector<DeviceDetails> deviceDetailsLogs;

public slots:
    void insertLogData(const DeviceDetails& newLog);

};

#endif // SERVICE_H
