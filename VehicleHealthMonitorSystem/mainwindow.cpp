#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the background color for the horizontal header
    QHeaderView *horizontalHeader = ui->tableWidget->horizontalHeader();
    horizontalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    // Set the background color for the vertical header
    QHeaderView *verticalHeader = ui->tableWidget->verticalHeader();
    verticalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    loadFilter();


    QTimer *timer = new QTimer();

    timer->setInterval(2000);
    timer->setSingleShot(false);

    connect(timer, &QTimer::timeout, [this]() {
        count--;
        if(count % 11 == 0) {loadStatus(0, 1, "good"); return;};
        if(count % 9 == 0) {loadStatus(1, 1, "critical"); return;};
        if(count % 7 == 0) {loadStatus(2, 1, "warning"); return;};
        if(count % 5 == 0){loadStatus(3, 1, "critical"); return;};
        loadStatus(3, 1, "critical");
    });

    timer->start();
}

void MainWindow::loadFilter(){
    FilterModel filters;
    QList<QString> filterList = filters.getFilterList();

    int rowsCount = filterList.count();
    ui->tableWidget->setRowCount(rowsCount);

    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("dd-MM-yyyy");

    for(int i=0; i<rowsCount; i++){
        QTableWidgetItem *filterListItem =  new QTableWidgetItem(filterList[i]);
        filterListItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,filterListItem);

        QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
        dateTableItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,2,dateTableItem);

        loadStatus(i, 1, "good");
    }
}


void MainWindow::loadStatus(int row, int count, QString status){
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);
    ui->tableWidget->setCellWidget(row, count, widget);

    int width = 25;
    int height = 25;

     label1->setFixedSize(width, height);

    if(status == "good"){
        QPixmap pixmap(":/images/Resources/check.png");
        label2->setText("Looks Good");
        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "warning"){
        QPixmap pixmap(":/images/Resources/warning.png");
        label2->setText("Warning !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "critical"){
        QPixmap pixmap(":/images/Resources/critical.jpg");
        label2->setText("Critical Problem !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
