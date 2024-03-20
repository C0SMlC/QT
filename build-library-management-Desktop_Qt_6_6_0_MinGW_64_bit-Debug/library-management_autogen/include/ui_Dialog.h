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

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QPlainTextEdit *insertBookName;
    QPlainTextEdit *insertBookCount;
    QLabel *label_2;
    QPushButton *insertButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(466, 382);
        Dialog->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"color:rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(211, 243, 255);"));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 51, 31));
        insertBookName = new QPlainTextEdit(Dialog);
        insertBookName->setObjectName("insertBookName");
        insertBookName->setGeometry(QRect(100, 90, 311, 31));
        insertBookCount = new QPlainTextEdit(Dialog);
        insertBookCount->setObjectName("insertBookCount");
        insertBookCount->setGeometry(QRect(100, 150, 311, 31));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 150, 51, 31));
        insertButton = new QPushButton(Dialog);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(120, 240, 111, 41));
        insertButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 200, 83);"));
        deleteButton = new QPushButton(Dialog);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(240, 240, 111, 41));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color:#D50000;"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Name :", nullptr));
        insertBookName->setPlainText(QCoreApplication::translate("Dialog", "jkhnbj\n"
"", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Count :", nullptr));
        insertButton->setText(QCoreApplication::translate("Dialog", "Insert", nullptr));
        deleteButton->setText(QCoreApplication::translate("Dialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
