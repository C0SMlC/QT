/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *BookList;
    QLabel *bookCount;
    QPushButton *updateButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 242, 241);\n"
"color:rgb(31, 13, 14);\n"
"font-weight:700;\n"
"font-size:18px;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 30, 351, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 13, 14);\n"
"font-weight:700;\n"
"font-size:26px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 210, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("padding: 6px 8px;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 310, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("padding: 6px 8px;"));
        BookList = new QComboBox(centralwidget);
        BookList->setObjectName("BookList");
        BookList->setGeometry(QRect(310, 210, 81, 31));
        BookList->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));
        BookList->setEditable(false);
        bookCount = new QLabel(centralwidget);
        bookCount->setObjectName("bookCount");
        bookCount->setGeometry(QRect(310, 310, 61, 41));
        bookCount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignCenter';"));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(350, 480, 141, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Library Management System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Book List :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Book Count :", nullptr));
        BookList->setCurrentText(QString());
        BookList->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        bookCount->setText(QString());
        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
