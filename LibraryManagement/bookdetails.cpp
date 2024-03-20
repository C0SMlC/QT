#include "bookdetails.h"
#include "ui_bookdetails.h"

BookDetails::BookDetails(BookManager& bookManager, QWidget *parent) :
    QWidget(parent),
    bookManager(bookManager),
    ui(new Ui::BookDetails)
{
    ui->setupUi(this);

    connect(ui->radioButton, &QRadioButton::toggled, this, &BookDetails::updateStackedWidget);
    connect(ui->radioButton_3, &QRadioButton::toggled, this, &BookDetails::updateStackedWidget);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &BookDetails::updateStackedWidget);

    renderTable(bookManager.getBooksWithCount("all"), "all");

}

void BookDetails::updateStackedWidget(){
    if(ui->radioButton->isChecked()){
//        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget->setCurrentWidget(ui->page_2);
        renderTable(bookManager.getBooksWithCount("all"), "all");
    }

    if(ui->radioButton_3->isChecked()){
//         ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget->setCurrentWidget(ui->page);
        renderTable(bookManager.getBooksWithCount("technical"), "technical");
    }

    if(ui->radioButton_2->isChecked()){
        //         ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget->setCurrentWidget(ui->page_5);
        renderTable(bookManager.getBooksWithCount("nonTechnical"), "nonTechnical");
    }
}

void BookDetails::renderTable(QList<std::pair<QString, int>> list, std::string filter) {
    QTableWidget* tableWidget;

    if (filter == "all") {
        tableWidget = ui->tableWidget_2;
    } else if (filter == "technical") {
        tableWidget = ui->tableWidget_4;
    } else if (filter == "nonTechnical") {
        tableWidget = ui->tableWidget_7;
    }

    tableWidget->clear();
    tableWidget->setRowCount(list.size());

    int row = 0;
    for (const auto& book : list) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(book.first);
        QTableWidgetItem* countItem = new QTableWidgetItem(QString::number(book.second));

        tableWidget->setItem(row, 0, nameItem);
        tableWidget->setItem(row, 1, countItem);

        ++row;
    }
}

BookDetails::~BookDetails()
{
    delete ui;
}
