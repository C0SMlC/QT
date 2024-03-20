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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *generateButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *deviceNameInput;
    QLabel *label_3;
    QLineEdit *serialNumberInput;
    QFrame *frame1;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *assignedInput;
    QLabel *label_5;
    QComboBox *locatiponCombobox;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_4;
    QPushButton *imageSelector;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 180, 248);\n"
"color: rgb(37, 43, 72)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 60, 331, 51));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(510, 470, 281, 84));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 15, 10, 15);
        saveButton = new QPushButton(widget);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("padding:10px 30px;\n"
"background-color: rgb(0, 230, 118);\n"
"font: 700 10pt \"Segoe UI\";"));

        horizontalLayout->addWidget(saveButton);

        generateButton = new QPushButton(widget);
        generateButton->setObjectName("generateButton");
        generateButton->setStyleSheet(QString::fromUtf8("padding: 10px 30px;\n"
"background-color: rgb(255, 255, 0);\n"
"font: 700 10pt \"Segoe UI\";"));

        horizontalLayout->addWidget(generateButton);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(130, 180, 341, 386));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(widget1);
        frame->setObjectName("frame");
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(30);
        formLayout->setContentsMargins(10, 30, 10, 30);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        deviceNameInput = new QLineEdit(frame);
        deviceNameInput->setObjectName("deviceNameInput");
        deviceNameInput->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"padding: 10px 20px;\n"
"background-color: rgb(243, 248, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, deviceNameInput);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        serialNumberInput = new QLineEdit(frame);
        serialNumberInput->setObjectName("serialNumberInput");
        serialNumberInput->setStyleSheet(QString::fromUtf8("padding: 10px 20px;\n"
"background-color: rgb(243, 248, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, serialNumberInput);


        verticalLayout->addWidget(frame);

        frame1 = new QFrame(widget1);
        frame1->setObjectName("frame1");
        formLayout_2 = new QFormLayout(frame1);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(15);
        formLayout_2->setVerticalSpacing(30);
        formLayout_2->setContentsMargins(10, 30, 10, 30);
        label_4 = new QLabel(frame1);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        assignedInput = new QLineEdit(frame1);
        assignedInput->setObjectName("assignedInput");
        assignedInput->setStyleSheet(QString::fromUtf8("padding: 10px 20px;\n"
"background-color: rgb(243, 248, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, assignedInput);

        label_5 = new QLabel(frame1);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        locatiponCombobox = new QComboBox(frame1);
        locatiponCombobox->setObjectName("locatiponCombobox");
        locatiponCombobox->setStyleSheet(QString::fromUtf8("padding: 10px 20px;\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(243, 248, 255);"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, locatiponCombobox);


        verticalLayout->addWidget(frame1);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(500, 270, 291, 71));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setSpacing(40);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setHorizontalSpacing(20);
        formLayout_4->setContentsMargins(10, 15, 10, 15);
        imageSelector = new QPushButton(widget2);
        imageSelector->setObjectName("imageSelector");
        imageSelector->setStyleSheet(QString::fromUtf8("padding: 10px 20px;\n"
"padding: 10px 20px;\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(243, 248, 255);"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, imageSelector);

        label_8 = new QLabel(widget2);
        label_8->setObjectName("label_8");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_8);


        verticalLayout_2->addLayout(formLayout_4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:700;\">Device Tracking System</span></p></body></html>", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Device Name   :</span></p></body></html>", nullptr));
        deviceNameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Device Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Serial Number :</span></p></body></html>", nullptr));
        serialNumberInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "786786848", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Assigned:</span></p></body></html>", nullptr));
        assignedInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pratik", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Location:</span></p></body></html>", nullptr));
        locatiponCombobox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        imageSelector->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Image :</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
