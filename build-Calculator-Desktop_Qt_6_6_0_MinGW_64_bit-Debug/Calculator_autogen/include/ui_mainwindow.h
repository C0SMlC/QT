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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *Input1;
    QLineEdit *Input2;
    QLabel *label;
    QLabel *signLabel;
    QLabel *label_3;
    QPushButton *pushButton;
    QRadioButton *addCheckbox;
    QRadioButton *subCheckbox;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(459, 595);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:black;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Input1 = new QLineEdit(centralwidget);
        Input1->setObjectName("Input1");
        Input1->setGeometry(QRect(40, 220, 101, 91));
        Input1->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"background-color:white;\n"
"color:black;\n"
"font-size:25px;"));
        Input2 = new QLineEdit(centralwidget);
        Input2->setObjectName("Input2");
        Input2->setGeometry(QRect(180, 220, 101, 91));
        Input2->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"background-color:white;\n"
"color:black;\n"
"font-size:25px;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 220, 91, 91));
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(70, 70, 70);\n"
"qproperty-alignment: 'AlignCenter';\n"
"color:white;\n"
"background-color:white;\n"
"color:black;\n"
"font-size:25px;"));
        signLabel = new QLabel(centralwidget);
        signLabel->setObjectName("signLabel");
        signLabel->setGeometry(QRect(150, 240, 21, 41));
        signLabel->setStyleSheet(QString::fromUtf8("font-size:35px;\n"
"color:white;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 240, 21, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-size:35px;\n"
"color:white;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 360, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"font-size:15px;"));
        addCheckbox = new QRadioButton(centralwidget);
        addCheckbox->setObjectName("addCheckbox");
        addCheckbox->setEnabled(true);
        addCheckbox->setGeometry(QRect(120, 150, 91, 22));
        addCheckbox->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        addCheckbox->setChecked(true);
        subCheckbox = new QRadioButton(centralwidget);
        subCheckbox->setObjectName("subCheckbox");
        subCheckbox->setGeometry(QRect(260, 150, 91, 22));
        subCheckbox->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 40, 111, 51));
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:25px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 459, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Input1->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Input2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        signLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700;\">+</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700;\">=</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Evaluate", nullptr));
        addCheckbox->setText(QCoreApplication::translate("MainWindow", "Addition", nullptr));
        subCheckbox->setText(QCoreApplication::translate("MainWindow", "Substraction", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
