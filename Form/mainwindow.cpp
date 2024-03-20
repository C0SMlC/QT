#include "mainwindow.h"
#include "PersonClass.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QSqlError>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handleSubmit);

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("your_host_name");
//    db.setDatabaseName("your_database_name");
//    db.setUserName("your_username");
//    db.setPassword("your_password");

//    if (!db.open()) {
//        qDebug() << "Error: Failed to connect to the database";
//    }

}


 void MainWindow::handleSubmit() {
    QString name = ui->nameInput->text();
    QString email = ui->emailInput->text();
    QString password = ui->passwordinput->text();
    QString confirmPassword = ui->confirmPasswordinput->text();

    if (password == confirmPassword && !name.isEmpty() && !email.isEmpty() ) {
        qDebug() << "Passwords match!";
        Person p1(string name,string email, string password, string confirmPassword);
        QMessageBox::information(this, "Success", "Form submitted successfully!");
    } else if(name.isEmpty() || email.isEmpty())
    {
        qDebug() << "name and email cant be empty!";
        QMessageBox::critical(this, "Error", "Name and Email cant be empty!");
    }else {
        qDebug() << "Passwords do not match!";
        QMessageBox::critical(this, "Error", "Passwords do not match. Please try again.");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


