/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPlainTextEdit *insertBookName;
    QPushButton *deleteButton;
    QLabel *label_2;
    QPlainTextEdit *insertBookCount;
    QLabel *label;
    QPushButton *insertButton;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(490, 377);
        Dialog->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color:  rgb(85, 85, 127);"));
        insertBookName = new QPlainTextEdit(Dialog);
        insertBookName->setObjectName("insertBookName");
        insertBookName->setGeometry(QRect(130, 60, 281, 41));
        deleteButton = new QPushButton(Dialog);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(240, 290, 151, 51));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color:#D50000;"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 140, 51, 31));
        insertBookCount = new QPlainTextEdit(Dialog);
        insertBookCount->setObjectName("insertBookCount");
        insertBookCount->setGeometry(QRect(130, 140, 281, 41));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 60, 51, 31));
        insertButton = new QPushButton(Dialog);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(100, 290, 131, 51));
        insertButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 156, 26)"));
        radioButton1 = new QRadioButton(Dialog);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setGeometry(QRect(130, 220, 91, 22));
        radioButton1->setChecked(true);
        radioButton2 = new QRadioButton(Dialog);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setGeometry(QRect(250, 220, 111, 22));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        insertBookName->setPlainText(QString());
        deleteButton->setText(QCoreApplication::translate("Dialog", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Count :", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Name :", nullptr));
        insertButton->setText(QCoreApplication::translate("Dialog", "Insert", nullptr));
        radioButton1->setText(QCoreApplication::translate("Dialog", "Technical", nullptr));
        radioButton2->setText(QCoreApplication::translate("Dialog", "Non-Technical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
