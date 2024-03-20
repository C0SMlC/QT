#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::emitLoadBookCountSlot(QString updatedText){
    emit emitLoadBookCount(updatedText, ui->bookCount);
}

void MainWindow::updateButtonClicked(bool value){
    emit createDialog(ui->BookList, ui->bookCount);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Library Management System");
    newLibrary = new LibraryInfo();
    Dialog *newDialog = new Dialog();
    connect(this, &MainWindow::loadBookList, newLibrary, &LibraryInfo::loadBooks);
    connect(this, &MainWindow::emitLoadBookCount, newLibrary, &LibraryInfo::updateCount);
    connect(ui->BookList, &QComboBox::textActivated, this, &MainWindow::emitLoadBookCountSlot);


    connect(ui->updateButton, &QPushButton::clicked,this , &MainWindow::updateButtonClicked);
    connect(this, &MainWindow::createDialog, newDialog ,&Dialog::createNewDialog);
//    connect(newDialog, &Dialog::insertBookSignal, newLibrary, &LibraryInfo::insertBookSlot);
    emit loadBookList(ui->BookList, ui->bookCount);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete newLibrary;
}

