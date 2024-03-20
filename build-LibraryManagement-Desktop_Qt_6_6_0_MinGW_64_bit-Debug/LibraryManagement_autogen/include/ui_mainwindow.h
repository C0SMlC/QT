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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QPushButton *updateButton;
    QComboBox *BookList;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QLabel *bookCount;
    QFrame *frame_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *addUserButton;
    QPlainTextEdit *addUserInput;
    QPushButton *detailsButton;
    QPushButton *assignBookButton;
    QPushButton *bookReturnButtton;
    QPushButton *BookDetailsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(975, 674);
        MainWindow->setStyleSheet(QString::fromUtf8("color:rgb(31, 13, 14);\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 410, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("padding: 6px 8px;"));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(800, 260, 141, 41));
        updateButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: rgb(170, 255, 127);\n"
"color: rgb(0, 0, 0);\n"
""));
        BookList = new QComboBox(centralwidget);
        BookList->setObjectName("BookList");
        BookList->setGeometry(QRect(230, 310, 91, 41));
        BookList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        BookList->setEditable(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 40, 661, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 13, 14);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:700;\n"
"font-size:40px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 310, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("padding: 6px 8px;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 230, 331, 271));
        frame->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        bookCount = new QLabel(frame);
        bookCount->setObjectName("bookCount");
        bookCount->setGeometry(QRect(190, 180, 91, 41));
        bookCount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignCenter';"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(410, 230, 361, 271));
        frame_2->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 20, 151, 41));
        label_4->setStyleSheet(QString::fromUtf8("padding: 6px 8px;\n"
"border:none"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 100, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("padding: 6px 8px;\n"
"border:none"));
        addUserButton = new QPushButton(frame_2);
        addUserButton->setObjectName("addUserButton");
        addUserButton->setGeometry(QRect(120, 190, 141, 41));
        addUserButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: rgb(85, 255, 0);\n"
"color: rgb(0, 0, 0);\n"
""));
        addUserInput = new QPlainTextEdit(frame_2);
        addUserInput->setObjectName("addUserInput");
        addUserInput->setGeometry(QRect(100, 100, 221, 41));
        addUserInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        detailsButton = new QPushButton(centralwidget);
        detailsButton->setObjectName("detailsButton");
        detailsButton->setGeometry(QRect(800, 350, 141, 41));
        detailsButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        assignBookButton = new QPushButton(centralwidget);
        assignBookButton->setObjectName("assignBookButton");
        assignBookButton->setGeometry(QRect(800, 440, 141, 41));
        assignBookButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 0, 0);"));
        bookReturnButtton = new QPushButton(centralwidget);
        bookReturnButtton->setObjectName("bookReturnButtton");
        bookReturnButtton->setGeometry(QRect(800, 530, 141, 41));
        bookReturnButtton->setCursor(QCursor(Qt::PointingHandCursor));
        bookReturnButtton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: #fdffcd;\n"
"color: rgb(0, 0, 0);\n"
""));
        BookDetailsButton = new QPushButton(centralwidget);
        BookDetailsButton->setObjectName("BookDetailsButton");
        BookDetailsButton->setGeometry(QRect(800, 170, 141, 41));
        BookDetailsButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:15px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        frame_2->raise();
        frame->raise();
        label_3->raise();
        updateButton->raise();
        BookList->raise();
        label->raise();
        label_2->raise();
        detailsButton->raise();
        assignBookButton->raise();
        bookReturnButtton->raise();
        BookDetailsButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Book Count :", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        BookList->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">Library Management System</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Book List :", nullptr));
        bookCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Create User</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        addUserButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        detailsButton->setText(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        assignBookButton->setText(QCoreApplication::translate("MainWindow", "Assign", nullptr));
        bookReturnButtton->setText(QCoreApplication::translate("MainWindow", "Book Return", nullptr));
        BookDetailsButton->setText(QCoreApplication::translate("MainWindow", "Book Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
