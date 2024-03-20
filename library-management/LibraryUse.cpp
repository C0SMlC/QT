#include "Library.h"

LibraryInfo::LibraryInfo() {
    bookMap = new std::map<QString, int>();
    (*bookMap)["C++"] = 2;
    (*bookMap)["Python"] = 1;
    (*bookMap)["Java"] = 3;
    (*bookMap)["Linux"] = 4;

    bookCountNumber = 0;

    // Connect the signal to the slot
    connect(this, &LibraryInfo::booksUpdated, this, &LibraryInfo::loadBooks);
}

void LibraryInfo::updateCount(QString updatedText, QLabel *bookCount){
    qDebug() << updatedText;
    bookCount->setText(QString::number((*bookMap)[updatedText]));
}

void LibraryInfo::loadBooks(QComboBox* bookList, QLabel *bookCount) {
    bookList->clear(); // Clear existing items in the combo box
    for (auto const &it : *bookMap) {
        bookList->addItem(it.first);
        bookCountNumber += it.second;
    }
    bookCount->setText(QString::number(bookCountNumber));
}

void LibraryInfo::insertBookSlot(QComboBox* bookList, QLabel *bookCount, QString bookName, int numOfBooks) {
    auto it = bookMap->find(bookName);

    if (it != bookMap->end()) {
        it->second += numOfBooks;
    } else {
        (*bookMap)[bookName] = numOfBooks;
    }

    // Emit the signal to notify that books have been updated
    emit booksUpdated(bookList, bookCount);

    qDebug() << "Updated bookMap contents:";
    for (const auto &entry : *bookMap) {
        qDebug() << entry.first << ": " << entry.second;
    }

    qDebug() << "-----";
}

LibraryInfo::~LibraryInfo() {
    delete bookMap;
}
