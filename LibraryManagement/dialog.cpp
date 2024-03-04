#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(BookManager &manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    bookManager(manager)
{
    ui->setupUi(this);
    this->setWindowTitle("Update Library");
    connect(ui->insertButton, SIGNAL(clicked()), this, SLOT(addBookToMap()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(removeBookFromMap()));
}

void Dialog::addBookToMap()
{
    QString bookTitle = ui->insertBookName->toPlainText();
    int bookCount = (ui->insertBookCount->toPlainText()).toInt();

    bookManager.addBook(bookTitle, bookCount);
    ui->insertBookName->clear();
    ui->insertBookCount->clear();

    emit updateBookListSignal();
    this->accept();
}

void Dialog::removeBookFromMap(){
    QString bookTitle = ui->insertBookName->toPlainText();
    int bookCount = (ui->insertBookCount->toPlainText()).toInt();

    bookManager.removeBook(bookTitle, bookCount);
    ui->insertBookName->clear();
    ui->insertBookCount->clear();

    emit updateBookListSignal();
    this->accept();
}


Dialog::~Dialog()
{
    delete ui;
}
