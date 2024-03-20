#include "Dialog.h"
#include "Library.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    LibraryInfo *newD= new LibraryInfo;
    connect(ui->insertButton, &QPushButton::clicked, this, &Dialog::throwInsertSignal);
    connect(this, &Dialog::insertBookSignal, newD, &LibraryInfo::insertBookSlot);
    // connect(this, &Dialog::loadBooks, newD, &LibraryInfo::loadBooks);
}

void Dialog::throwInsertSignal(bool value){
    qDebug() << "Hoyahdnfghn";
    QString bookName = ui->insertBookName->toPlainText().trimmed();
       qDebug() << "Hoyahdnfghn";
    int numOfBooks = (ui->insertBookCount->toPlainText()).toInt();
          qDebug() << "Hoyahdnfghn";
//    this->bookCount->setText(QString::number(99999999));
           qDebug() << "Hoyahdnfghn";
    qDebug() << bookName.toStdString() << numOfBooks;

    if(bookList == nullptr) qDebug() << "uhigu";

//     bookCount->setText(QString::number(99999999));

//    emit insertBookSignal(this->bookList, this->bookCount, bookName, numOfBooks);
}


void Dialog::createNewDialog(QComboBox* bookLis, QLabel* bookCoun){
//    bookList = bookLis;
    bookCount = bookCoun;
    bookCount->setText(QString::number(99999999));
    newDialog = new Dialog(this);
    newDialog->show();

}



Dialog::~Dialog()
{
    delete ui;
    delete newDialog;
}
