/********************************************************************************
** Form generated from reading UI file 'bookreturndialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRETURNDIALOG_H
#define UI_BOOKRETURNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BookReturnDialog
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QTextEdit *bookCountBox;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QComboBox *bookComboBox;

    void setupUi(QDialog *BookReturnDialog)
    {
        if (BookReturnDialog->objectName().isEmpty())
            BookReturnDialog->setObjectName("BookReturnDialog");
        BookReturnDialog->resize(827, 628);
        BookReturnDialog->setAutoFillBackground(false);
        BookReturnDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        label = new QLabel(BookReturnDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 50, 271, 41));
        label->setStyleSheet(QString::fromUtf8("font: 36pt \"Segoe UI\";\n"
"font-weight:600;"));
        comboBox = new QComboBox(BookReturnDialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(330, 190, 281, 41));
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16pt \"Segoe UI\";\n"
""));
        label_2 = new QLabel(BookReturnDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 190, 151, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));
        bookCountBox = new QTextEdit(BookReturnDialog);
        bookCountBox->setObjectName("bookCountBox");
        bookCountBox->setGeometry(QRect(330, 370, 71, 41));
        bookCountBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 16pt \"Segoe UI\";"));
        label_4 = new QLabel(BookReturnDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 370, 161, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));
        pushButton = new QPushButton(BookReturnDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 480, 171, 51));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Segoe UI\";\n"
"background-color: rgb(189, 189, 189);\n"
"color: rgb(0, 0, 0);\n"
"font: 16pt \"Segoe UI\";"));
        label_5 = new QLabel(BookReturnDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 280, 161, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));
        bookComboBox = new QComboBox(BookReturnDialog);
        bookComboBox->setObjectName("bookComboBox");
        bookComboBox->setGeometry(QRect(330, 280, 281, 41));
        bookComboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16pt \"Segoe UI\";\n"
""));

        retranslateUi(BookReturnDialog);

        QMetaObject::connectSlotsByName(BookReturnDialog);
    } // setupUi

    void retranslateUi(QDialog *BookReturnDialog)
    {
        BookReturnDialog->setWindowTitle(QCoreApplication::translate("BookReturnDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BookReturnDialog", "Return Book", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("BookReturnDialog", "Select User", nullptr));
        label_2->setText(QCoreApplication::translate("BookReturnDialog", "Select User:", nullptr));
        bookCountBox->setHtml(QCoreApplication::translate("BookReturnDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:16pt; font-weight:700; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        bookCountBox->setPlaceholderText(QCoreApplication::translate("BookReturnDialog", "Count", nullptr));
        label_4->setText(QCoreApplication::translate("BookReturnDialog", "Book Count:", nullptr));
        pushButton->setText(QCoreApplication::translate("BookReturnDialog", "Confirm Return", nullptr));
        label_5->setText(QCoreApplication::translate("BookReturnDialog", "Select Name:", nullptr));
        bookComboBox->setPlaceholderText(QCoreApplication::translate("BookReturnDialog", "Select Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookReturnDialog: public Ui_BookReturnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRETURNDIALOG_H
