#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->imageSelector, &QPushButton::clicked, this, &MainWindow::selectImage);
}

void MainWindow::selectImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Image", QDir::homePath(), "Image Files (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        QString justFileName = fileInfo.fileName();
        ui->imageSelector->setText(justFileName);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

