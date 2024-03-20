/********************************************************************************
** Form generated from reading UI file 'bookdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDETAILS_H
#define UI_BOOKDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookDetails
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QTableWidget *tableWidget_2;
    QLabel *label;
    QWidget *page_5;
    QTableWidget *tableWidget_7;
    QLabel *label_4;
    QWidget *page;
    QTableWidget *tableWidget;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QTableWidget *tableWidget_3;
    QWidget *page_4;
    QTableWidget *tableWidget_4;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *BookDetails)
    {
        if (BookDetails->objectName().isEmpty())
            BookDetails->setObjectName("BookDetails");
        BookDetails->resize(828, 646);
        BookDetails->setStyleSheet(QString::fromUtf8("color:rgb(31, 13, 14);\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(BookDetails);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(90, 90, 661, 451));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        tableWidget_2 = new QTableWidget(page_2);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(110, 100, 471, 301));
        tableWidget_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(0, 0, 0)"));
        tableWidget_2->setColumnCount(2);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(250);
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 40, 91, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 16pt \"Segoe UI\";"));
        stackedWidget->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        tableWidget_7 = new QTableWidget(page_5);
        if (tableWidget_7->columnCount() < 2)
            tableWidget_7->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_7->setObjectName("tableWidget_7");
        tableWidget_7->setGeometry(QRect(120, 100, 471, 301));
        tableWidget_7->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(0, 0, 0)"));
        tableWidget_7->setColumnCount(2);
        tableWidget_7->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_7->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_7->horizontalHeader()->setDefaultSectionSize(250);
        label_4 = new QLabel(page_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 40, 141, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 16pt \"Segoe UI\";"));
        stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName("page");
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(90, 40, 471, 301));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(255, 255, 255);"));
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setDefaultSectionSize(250);
        stackedWidget_2 = new QStackedWidget(page);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 661, 451));
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tableWidget_3 = new QTableWidget(page_3);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(90, 40, 471, 301));
        tableWidget_3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(255, 255, 255);"));
        tableWidget_3->setColumnCount(2);
        tableWidget_3->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(250);
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        tableWidget_4 = new QTableWidget(page_4);
        if (tableWidget_4->columnCount() < 2)
            tableWidget_4->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(110, 100, 471, 301));
        tableWidget_4->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(0, 0, 0)"));
        tableWidget_4->setColumnCount(2);
        tableWidget_4->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(250);
        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 40, 161, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 16pt \"Segoe UI\";"));
        stackedWidget_2->addWidget(page_4);
        stackedWidget->addWidget(page);
        radioButton = new QRadioButton(BookDetails);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(220, 540, 51, 22));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(BookDetails);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(530, 540, 151, 22));
        radioButton_3 = new QRadioButton(BookDetails);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(350, 540, 111, 22));

        retranslateUi(BookDetails);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BookDetails);
    } // setupUi

    void retranslateUi(QWidget *BookDetails)
    {
        BookDetails->setWindowTitle(QCoreApplication::translate("BookDetails", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BookDetails", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BookDetails", "Count", nullptr));
        label->setText(QCoreApplication::translate("BookDetails", "All books", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BookDetails", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BookDetails", "Count", nullptr));
        label_4->setText(QCoreApplication::translate("BookDetails", "Non-Technical", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BookDetails", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BookDetails", "Count", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("BookDetails", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("BookDetails", "Count", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("BookDetails", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("BookDetails", "Count", nullptr));
        label_2->setText(QCoreApplication::translate("BookDetails", "Technical Books", nullptr));
        radioButton->setText(QCoreApplication::translate("BookDetails", "All", nullptr));
        radioButton_2->setText(QCoreApplication::translate("BookDetails", "Non-Technical", nullptr));
        radioButton_3->setText(QCoreApplication::translate("BookDetails", "Technical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookDetails: public Ui_BookDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDETAILS_H
