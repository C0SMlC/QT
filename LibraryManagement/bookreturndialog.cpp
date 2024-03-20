#include "bookreturndialog.h"
#include "ui_bookreturndialog.h"

#include <QMessageBox>

BookReturnDialog::BookReturnDialog(std::map<int, std::pair<QString, std::pair<QString, int>>>& logs, BookManager& books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookReturnDialog),
    libraryLogs(logs),
    booksList(books)
{
    ui->setupUi(this);
    QList<QString> users;

    for(auto const& it: libraryLogs){
        if(!users.contains(it.second.second.first))
        {
            users.append(it.second.second.first);
        }
    }

    if(users.empty()){
        QMessageBox::information(nullptr, "Error!", "No Logs Added!");
        return;
    } else {
        ui->comboBox->addItems(users);
    }

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &BookReturnDialog::updateBooksComboBox);
    connect(ui->bookComboBox, &QComboBox::currentTextChanged, this, &BookReturnDialog::updateValues);
    connect(ui->pushButton, &QPushButton::clicked, this, &BookReturnDialog::updateLibrary);
}

void BookReturnDialog::updateBooksComboBox(const QString& userName) {
    ui->bookComboBox->clear();

    for (auto const& it : libraryLogs) {
        if (it.second.second.first == userName) {
            ui->bookComboBox->addItem(it.second.first);
        }
    }

    if (ui->bookComboBox->count() == 0) {
        QMessageBox::information(nullptr, "Error!", "No Books Found for the Selected User!");
    }
}

void BookReturnDialog::updateLibrary() {
    bookCount = ui->bookCountBox->toPlainText().toInt();
    bool isTechnical = true;
//    if (ui->radioButton2->isChecked()) {
//        isTechnical = false;
//    }

    qDebug() << "Book Name :" << bookName << " bookCount: " << bookCount << " isTechnical: " << isTechnical << " Total Borrowed Count: " << totalBorrowedCount;

    if (bookCount > totalBorrowedCount) {
        QMessageBox::warning(nullptr, "Error returning book", "You can only return the books you have borrowed!");
        return;
    }
    if (bookCount < totalBorrowedCount && bookCount > 0) {
        qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxxx" << libraryLogs[this->logId].second.second;
        libraryLogs[this->logId].second.second = libraryLogs[this->logId].second.second - bookCount;
    } else if (bookCount == totalBorrowedCount) {
        libraryLogs.erase(this->logId);
    }

    booksList.addBook(bookName, bookCount, isTechnical);
    emit updateCountLabel();
    this->accept();
}

void BookReturnDialog::updateValues(const QString& bookName) {
    qDebug() <<"The recieved bookname is "<<bookName<<"/n";
    for(auto const &it : libraryLogs){
        if(it.second.first == bookName && it.second.second.first == ui->comboBox->currentText()) {
            qDebug() <<"The if statement bookname is "<<it.second.first<<"/n";
            qDebug() <<"The if statement second parameter is "<< ui->comboBox->currentText()<<"/n";

            ui->bookCountBox->setText(QString::number(it.second.second.second));
            this->bookName = it.second.first;
            this->logId = it.first;
            this->totalBorrowedCount = it.second.second.second;
        }
    }
}

BookReturnDialog::~BookReturnDialog()
{
    delete ui;
}
