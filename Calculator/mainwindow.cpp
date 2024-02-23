#include <iostream>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString inputText1 = ui->Input1->text();
    double operand1 = inputText1.toDouble();

    QString inputText2 = ui->Input2->text();
    double operand2 = inputText2.toDouble();

    bool addChecked = ui->addCheckbox->isChecked();
    bool subtractChecked = ui->subCheckbox->isChecked();

    double result;

    if (addChecked && !subtractChecked)
    {
        result = operand1 + operand2;
    }
    else
    {
        result = operand1 - operand2;
    }

    qDebug() << "Result:" << QString::number(result);
    ui->label->setText(QString::number(result, 'f', 2));
}

void MainWindow::on_addCheckbox_toggled(bool checked)
{
    if(checked) ui->signLabel->setText(QString('+'));
    if(!checked) ui->signLabel->setText(QString('-'));
}
