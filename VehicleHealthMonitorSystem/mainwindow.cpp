#include "mainwindow.h"
#include "./ui_mainwindow.h"

void loadDefaults(){
    QList<QString> filterList = {"Engine Air Filter", "Cabin Air Filter", "Oil Filter", "Fuel Filter"};
    for(const auto& filter : filterList){
        FilterModel newFilter(filter);
        FilterModel::addFilterToList(newFilter);
    }

    QList<QString> FluidList = {"Engine Oil", "Hydraulic Oil", "Coolant Oil", "Fuel"};
    for(const auto& fluid : FluidList){
        FluidModel newFluid(fluid);
        FluidModel::addFluidToList(newFluid);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Vehicle Health Monitor System");

    QHeaderView *horizontalHeader = ui->tableWidget->horizontalHeader();
    horizontalHeader->setStyleSheet("background-color: #2962FF; color: #263238;");

    QHeaderView *horizontalHeaderFluidTable = ui->tableWidget_2->horizontalHeader();
    horizontalHeaderFluidTable->setStyleSheet("background-color: #2962FF; color: #263238;");

    loadDefaults();

    ui->stackedWidget->setCurrentWidget(ui->page_2);

    load("fluid");
    load("filter");


    timer = new QTimer();

    timer->setInterval(1000);
    timer->setSingleShot(false);

    connect(timer, &QTimer::timeout,this, &MainWindow::handleFluidValueChange);
    connect(timer, &QTimer::timeout,this, &MainWindow::handleFilterValueChange);

    timer->start();
}

void MainWindow::load(QString type){
    if(type == "filter"){
        qDebug() << "in the function";

        QList<FilterModel> filterList = FilterModel::filterList;
        int rowsCount = filterList.count();
        ui->tableWidget->setRowCount(rowsCount);
        QDate currentDate = QDate::currentDate();
        QString dateString = currentDate.toString("dd-MM-yyyy");

        for(int i=0; i<rowsCount; i++){
            qDebug() << filterList[i].getFilterName();
            QTableWidgetItem *filterListItem =  new QTableWidgetItem(filterList[i].getFilterName());
            filterListItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i,0,filterListItem);

            QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
            dateTableItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i,2,dateTableItem);

            loadStatus(i, 1, "good", "filter");
        }
    }else{
        QList<FluidModel> fluidList = FluidModel::fluidList;
        int rowsCount = fluidList.count();
        ui->tableWidget_2->setRowCount(rowsCount);
        QDate currentDate = QDate::currentDate();
        QString dateString = currentDate.toString("dd-MM-yyyy");

        for(int i=0; i<rowsCount; i++){
            QTableWidgetItem *filterListItem =  new QTableWidgetItem(fluidList[i].getFluidName());
            filterListItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->setItem(i,0,filterListItem);

            QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
            dateTableItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->setItem(i,2,dateTableItem);

            loadStatus(i, 1, "good", "fluid");
        }
    }
}

void MainWindow::handleFluidValueChange(){
    if(fluidCount == 25) timer->stop();
    QList<FilterModel>& filterList = FilterModel::filterList;

    for(int i=0; i<filterList.count(); i++){
        filterList[i] = filterList[i].setFilterHealth(i+1);
        int healthLevel = filterList[i].getFilterHealth();

        if(healthLevel > 80) loadStatus(i, 1, "good", "fluid");
        else if(healthLevel > 50 && healthLevel < 80) loadStatus(i, 1, "warning", "fluid");
        else loadStatus(i, 1, "critical", "fluid");
    }

    fluidCount--;
}

void MainWindow::handleFilterValueChange(){
    if(filterCount == 25) timer->stop();
    QList<FilterModel>& filterList = FilterModel::filterList;

    for(int i=0; i<filterList.count(); i++){
        filterList[i] = filterList[i].setFilterHealth((i/2)+1);
        int healthLevel = filterList[i].getFilterHealth();

        if(healthLevel > 80) loadStatus(i, 1, "good", "filter");
        else if(healthLevel > 50 && healthLevel < 80) loadStatus(i, 1, "warning", "filter");
        else loadStatus(i, 1, "critical", "filter");
    }

    filterCount--;
}


void MainWindow::loadStatus(int row, int column, QString status, QString type){
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);
    if(type=="filter") ui->tableWidget->setCellWidget(row, column, widget);
    else ui->tableWidget_2->setCellWidget(row, column, widget);

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


void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void MainWindow::on_pushButton_2_clicked()
{
      ui->stackedWidget->setCurrentWidget(ui->page);
}

