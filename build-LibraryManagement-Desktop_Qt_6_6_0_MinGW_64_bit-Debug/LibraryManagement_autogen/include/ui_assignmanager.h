/********************************************************************************
** Form generated from reading UI file 'assignmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMANAGER_H
#define UI_ASSIGNMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssignManager
{
public:
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QComboBox *nameComboBox;
    QLabel *bookNameLabel;
    QComboBox *bookNameComboBox;
    QLabel *countLabel;
    QLineEdit *countLineEdit;
    QPushButton *pushButton;
    QLabel *bookCountLabel;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QFrame *formFrame_2;
    QFormLayout *formLayout_3;

    void setupUi(QWidget *AssignManager)
    {
        if (AssignManager->objectName().isEmpty())
            AssignManager->setObjectName("AssignManager");
        AssignManager->resize(866, 555);
        AssignManager->setStyleSheet(QString::fromUtf8("color:rgb(31, 13, 14);\n"
"background-color: rgb(85, 85, 127);\n"
"font-weight:700;\n"
"font-size:18px;\n"
"color: rgb(255, 255, 255);"));
        formGroupBox = new QGroupBox(AssignManager);
        formGroupBox->setObjectName("formGroupBox");
        formGroupBox->setGeometry(QRect(220, 140, 441, 231));
        formGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"padding:15px 10px;\n"
"border:none;\n"
"border-radius:15px;"));
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(formGroupBox);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameComboBox = new QComboBox(formGroupBox);
        nameComboBox->setObjectName("nameComboBox");
        nameComboBox->setStyleSheet(QString::fromUtf8("border:1px solid black;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameComboBox);

        bookNameLabel = new QLabel(formGroupBox);
        bookNameLabel->setObjectName("bookNameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, bookNameLabel);

        bookNameComboBox = new QComboBox(formGroupBox);
        bookNameComboBox->setObjectName("bookNameComboBox");
        bookNameComboBox->setStyleSheet(QString::fromUtf8("border:1px solid black;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, bookNameComboBox);

        countLabel = new QLabel(formGroupBox);
        countLabel->setObjectName("countLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, countLabel);

        countLineEdit = new QLineEdit(formGroupBox);
        countLineEdit->setObjectName("countLineEdit");
        countLineEdit->setStyleSheet(QString::fromUtf8("border:1px solid black;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, countLineEdit);

        pushButton = new QPushButton(AssignManager);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 420, 241, 51));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(247, 247, 247);\n"
"border-radius:10px;"));
        bookCountLabel = new QLabel(AssignManager);
        bookCountLabel->setObjectName("bookCountLabel");
        bookCountLabel->setGeometry(QRect(670, 230, 61, 51));
        bookCountLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border:1px solid black;"));
        radioButton = new QRadioButton(AssignManager);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(230, 70, 91, 22));
        radioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(AssignManager);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(360, 70, 111, 22));
        radioButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        radioButton_3 = new QRadioButton(AssignManager);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(500, 70, 151, 22));
        radioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        formFrame_2 = new QFrame(AssignManager);
        formFrame_2->setObjectName("formFrame_2");
        formFrame_2->setGeometry(QRect(220, 50, 441, 61));
        formFrame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"padding:15px 10px;\n"
"border:none;\n"
"border-radius:15px;"));
        formLayout_3 = new QFormLayout(formFrame_2);
        formLayout_3->setObjectName("formLayout_3");
        formFrame_2->raise();
        formGroupBox->raise();
        pushButton->raise();
        bookCountLabel->raise();
        radioButton->raise();
        radioButton_2->raise();
        radioButton_3->raise();

        retranslateUi(AssignManager);

        QMetaObject::connectSlotsByName(AssignManager);
    } // setupUi

    void retranslateUi(QWidget *AssignManager)
    {
        AssignManager->setWindowTitle(QCoreApplication::translate("AssignManager", "Form", nullptr));
        nameLabel->setText(QCoreApplication::translate("AssignManager", "Name", nullptr));
        nameComboBox->setPlaceholderText(QCoreApplication::translate("AssignManager", "Select", nullptr));
        bookNameLabel->setText(QCoreApplication::translate("AssignManager", "Book Name", nullptr));
        bookNameComboBox->setPlaceholderText(QCoreApplication::translate("AssignManager", "Select", nullptr));
        countLabel->setText(QCoreApplication::translate("AssignManager", "Count", nullptr));
        countLineEdit->setText(QCoreApplication::translate("AssignManager", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("AssignManager", "Assign Book", nullptr));
        bookCountLabel->setText(QCoreApplication::translate("AssignManager", "None", nullptr));
        radioButton->setText(QCoreApplication::translate("AssignManager", "All", nullptr));
        radioButton_2->setText(QCoreApplication::translate("AssignManager", "Technical", nullptr));
        radioButton_3->setText(QCoreApplication::translate("AssignManager", "Non-Technical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignManager: public Ui_AssignManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMANAGER_H
