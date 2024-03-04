#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), dialog(bookManager)
{
    ui->setupUi(this);
    this->setWindowTitle("Library Management System");
    updateDetails();

    ui->updateButton->setCursor(Qt::PointingHandCursor);
    ui->addUserButton->setCursor(Qt::PointingHandCursor);
    ui->detailsButton->setCursor(Qt::PointingHandCursor);
    ui->assignBookButton->setCursor(Qt::PointingHandCursor);

    users.insert("Pratik");
    users.insert("John Cena");

    connect(ui->BookList, &QComboBox::currentTextChanged, this, &MainWindow::handleBookChange);
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::openDialog);
    connect(ui->addUserButton, &QPushButton::clicked, this, &MainWindow::addUser);
    connect(ui->detailsButton, &QPushButton::clicked, this, &MainWindow::openLogs);
    connect(ui->assignBookButton, &QPushButton::clicked, this, &MainWindow::openAssignWindow);
    connect(&dialog, SIGNAL(updateBookListSignal()), this, SLOT(updateDetails()));
}

void MainWindow::handleBookChange(const QString &bookName){
    ui->bookCount->clear();
    int bookCount = bookManager.getBookCount(bookName);
    ui->bookCount->setNum(bookCount);
}

void MainWindow::openLogs(){
    qDebug() <<"clicked";
    newLogsWindow = new LibraryLogs(libraryLogs, totalRentedCount);
    newLogsWindow->setWindowModality(Qt::ApplicationModal);
    newLogsWindow->show();
}

void MainWindow::addUser(){
    QString userName = ui->addUserInput->toPlainText();
    qDebug() << userName;

    if (users.find(userName) != users.end()) {
        QMessageBox::warning(nullptr, "User Already Exists!", "The specified user already exists.");
        ui->addUserInput->clear();
        return;
    }

    users.insert(userName);
    QMessageBox::information(nullptr, "User Added!", "The specified user added successfully.");
    ui->addUserInput->clear();
}

void MainWindow::updateBookListComboBox() {
    ui->BookList->clear();
    QList<QString> bookTitles = bookManager.getBookTitles();
    ui->BookList->addItems(bookTitles);
}

void MainWindow::updateTotalBookCount() {
    ui->bookCount->clear();
    int bookTotalCount = bookManager.getTotalCount();
    ui->bookCount->setNum(bookTotalCount);
    qDebug() << "updated the count"<<bookTotalCount;
}


void MainWindow::updateDetails(){
    updateBookListComboBox();
    updateTotalBookCount();
}

void MainWindow::openDialog()
{
    dialog.exec();
}

void MainWindow::openAssignWindow()
{
    assignBook = new AssignManager(users, bookManager, totalRentedCount, libraryLogs);
    connect(assignBook, &AssignManager::updateCountLabel, this, &MainWindow::updateTotalBookCount);
    assignBook->setWindowModality(Qt::ApplicationModal);
    assignBook->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete assignBook;
}

