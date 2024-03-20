#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");       // Replace with your actual MySQL hostname
    db.setDatabaseName("myqtdata");    // Replace with your database name
    db.setUserName("your_username");   // Replace with your MySQL username
    db.setPassword("your_password");   // Replace with your MySQL password

    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError();
        return -1;
    } else {
        qDebug() << "Connected to the database!";

        // Example: Basic query to verify connection
        QSqlQuery query(db);
        if (query.exec("SHOW TABLES")) {
            qDebug() << "Tables in the database:";
            while (query.next()) {
                qDebug() << query.value(0).toString();
            }
        }

        db.close(); // Close the connection when done
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

