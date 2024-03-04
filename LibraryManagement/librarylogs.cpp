#include "librarylogs.h"
#include "ui_librarylogs.h"

LibraryLogs::LibraryLogs(std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs,int &totalLogsCount, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibraryLogs),
    libraryLogs(libraryLogs),
    totalLogsCount(totalLogsCount)
{
    ui->setupUi(this);
    this->setWindowTitle("Library Details");

    ui->logsTable->setRowCount(10);
    ui->logsTable->setColumnCount(3);


    ui->logsTable->setItem(0, 0, new QTableWidgetItem(QString("Pratik")));
    ui->logsTable->setItem(0, 1, new QTableWidgetItem(QString("Python")));
    ui->logsTable->setItem(0, 2, new QTableWidgetItem(QString("10")));

    int row = 1;


    for (const auto &logEntry : libraryLogs) {
        const QString userName = logEntry.second.second.first;
        const int bookCount = logEntry.second.second.second;
        const QString bookDetails = logEntry.second.first;

        ui->logsTable->setItem(row, 0, new QTableWidgetItem(userName));
        ui->logsTable->setItem(row, 1, new QTableWidgetItem(bookDetails));
        ui->logsTable->setItem(row, 2, new QTableWidgetItem(QString::number(bookCount)));

        ++row;
    }


}

LibraryLogs::~LibraryLogs()
{
    delete ui;
}
