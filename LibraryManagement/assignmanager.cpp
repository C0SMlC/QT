#include "assignmanager.h"
#include "ui_assignmanager.h"

#include <QMessageBox>

AssignManager::AssignManager(std::set<QString>& userSet, BookManager &bookList, int &totalLogsCount,  std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignManager),
    users(userSet),
    books(bookList),
    totalLogsCount(totalLogsCount),
    libraryLogs(libraryLogs)

{
    ui->setupUi(this);
    this->setWindowTitle("Rent a book");
    qDebug() <<"Hiii";

    for(auto const &user: users){
        qDebug() << "jndikn";
        ui->nameComboBox->addItem(user);

    }

    ui->bookNameComboBox->addItems(books.getBookTitles());
    connect(ui->pushButton, &QPushButton::clicked, this, &AssignManager::updateDetails);
    connect(ui->bookNameComboBox, &QComboBox::currentTextChanged, this, &AssignManager::updateCountLable);
}

void AssignManager::updateCountLable(const QString &book){
    ui->bookCountLabel->setNum(books.getBookCount(book));
    qDebug() << "books.getBookCount(book)"<<books.getBookCount(book);
}

void AssignManager::updateDetails() {
    QString userName = ui->nameComboBox->currentText();
    QString bookName = ui->bookNameComboBox->currentText();
    int bookCount = (ui->countLineEdit->text()).toInt();

    if(books.getBookCount(bookName) < bookCount){
        QMessageBox::warning(nullptr, "Error", "Not enough books available!");
        return;
    }

    books.updateBook(bookName, bookCount);
    std::pair<QString, std::pair<QString, int>> logDetails = std::make_pair(bookName, std::make_pair(userName, bookCount));
    libraryLogs[totalLogsCount++] = logDetails;
    qDebug() << userName << bookName << bookCount << totalLogsCount;

    emit updateCountLabel();
    this->close();
}


AssignManager::~AssignManager()
{
    delete ui;
}
