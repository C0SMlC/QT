#include "mainwindow.h"
#include "iostream"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newDialog = new Dialog(this);
    connect(newDialog, &Dialog::closeButtonClicked, this, &MainWindow::closeWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!newDialog->isVisible())
    {
        newDialog->show();
        newDialog->exec();
        std::cout << "Window Opened" << std::endl;
    }
    else
    {
        std::cout << "Window already Opened" << std::endl;
    }
}


void MainWindow::closeWindow()
{
    close();
    newDialog->close();
}
