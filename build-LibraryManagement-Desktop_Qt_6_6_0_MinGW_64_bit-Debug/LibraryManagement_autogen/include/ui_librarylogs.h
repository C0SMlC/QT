/********************************************************************************
** Form generated from reading UI file 'librarylogs.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYLOGS_H
#define UI_LIBRARYLOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryLogs
{
public:
    QTableWidget *logsTable;
    QLabel *label;

    void setupUi(QWidget *LibraryLogs)
    {
        if (LibraryLogs->objectName().isEmpty())
            LibraryLogs->setObjectName("LibraryLogs");
        LibraryLogs->resize(906, 639);
        LibraryLogs->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        logsTable = new QTableWidget(LibraryLogs);
        if (logsTable->columnCount() < 3)
            logsTable->setColumnCount(3);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        logsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        logsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        logsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        logsTable->setObjectName("logsTable");
        logsTable->setGeometry(QRect(100, 140, 711, 451));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        logsTable->setFont(font2);
        logsTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        logsTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 12pt \"Sans Serif Collection\";"));
        logsTable->setAlternatingRowColors(true);
        logsTable->setSortingEnabled(false);
        logsTable->setColumnCount(3);
        logsTable->horizontalHeader()->setCascadingSectionResizes(true);
        logsTable->horizontalHeader()->setDefaultSectionSize(223);
        label = new QLabel(LibraryLogs);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 20, 231, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 13, 14);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:700;\n"
"font-size:40px;"));

        retranslateUi(LibraryLogs);

        QMetaObject::connectSlotsByName(LibraryLogs);
    } // setupUi

    void retranslateUi(QWidget *LibraryLogs)
    {
        LibraryLogs->setWindowTitle(QCoreApplication::translate("LibraryLogs", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LibraryLogs", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LibraryLogs", "Book Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LibraryLogs", "Count", nullptr));
        label->setText(QCoreApplication::translate("LibraryLogs", "<html><head/><body><p>Library Logs </p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibraryLogs: public Ui_LibraryLogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYLOGS_H
