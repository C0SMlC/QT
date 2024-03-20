#include <QList>
#include <QDebug>
#include "bookmanager.h"

BookManager::BookManager() {
    totalBookCount = 0;
    this->createDummyData("C++", 10, true);
    this->createDummyData("Java", 5, true);
    this->createDummyData("Python", 4, true);
    this->createDummyData("Science", 1, false);
}

void BookManager::createDummyData(const QString& name, int count, bool isTechnical) {
    Book newBook(name, isTechnical, count);
    bookMap.emplace(++totalBookCount, newBook);
}

bool BookManager::findBook(const QString& bookTitle) {
    for (auto const& bookObject : bookMap) {
        if (bookObject.second.title == bookTitle) {
            return true;
        }
    }
    return false;
}

QList<std::pair<QString, int>> BookManager::getBooksWithCount(std::string filter) {
    QList<std::pair<QString, int>> list;

    if(filter == "all"){
        for (const auto& entry : bookMap) {
            list.append(std::make_pair(entry.second.title, entry.second.count));
        }
        qDebug() << "redering all books";
    }

    if(filter == "technical"){
        for (const auto& entry : bookMap) {
            if(entry.second.isTechnical){
              list.append(std::make_pair(entry.second.title, entry.second.count));
            }
        }
        qDebug() << "redering technical books";
    }

    if(filter == "nonTechnical"){
        for (const auto& entry : bookMap) {
            if(!entry.second.isTechnical){
               list.append(std::make_pair(entry.second.title, entry.second.count));
            }
        }

        qDebug() << "redering nonTechnical books";
    }
    return list;
}

void BookManager::updateCount(const Book& newBook, int count, bool isIncrement) {
    for (auto& bookObject : bookMap) {
        if (bookObject.second.title == newBook.title) {
            if (isIncrement) {
                bookObject.second.count += count;
            } else {
                bookObject.second.count -= count;
            }
            break;
        }
    }
}

void BookManager::addBook(const QString& bookTitle, const int count, const bool isTechnical) {
    Book newBook(bookTitle, isTechnical, count);
    bool isBookPresent = findBook(newBook.title);

    if (isBookPresent) {
        updateCount(newBook, count, true);
    } else {
        bookMap.emplace(++totalBookCount, newBook);
    }
}

bool BookManager::removeBook(const QString& bookTitle, int count) {
    bool isBookPresent = findBook(bookTitle);

    if (isBookPresent) {
        for (auto& bookObject : bookMap) {
            if (bookObject.second.title == bookTitle) {
                if (bookObject.second.count >= count) {
                    bookObject.second.count -= count;
                    if (bookObject.second.count == 0) {
                        bookMap.erase(bookObject.first);
                        totalBookCount--;
                    }
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

int BookManager::getBookCount(const QString& bookTitle) {
    for (const auto& bookObject : bookMap) {
        if (bookObject.second.title == bookTitle) {
            return bookObject.second.count;
        }
    }
    return 0;
}

QList<QString> BookManager::getBookTitles(std::string filter="all") const {
    QList<QString> titles;
    if(filter == "all"){
        for (const auto& entry : bookMap) {
            titles.append(entry.second.title);
        }
        qDebug() << "redering all books";
    }

    if(filter == "technical"){
        for (const auto& entry : bookMap) {
            if(entry.second.isTechnical){
                titles.append(entry.second.title);
            }
        }
         qDebug() << "redering technical books";
    }

    if(filter == "nonTechnical"){
        for (const auto& entry : bookMap) {
            if(!entry.second.isTechnical){
                titles.append(entry.second.title);
            }
        }

         qDebug() << "redering nonTechnical books";
    }
    return titles;
}

void BookManager::updateBook(const QString& bookTitle, int count, bool increment) {
    for (auto& bookObject : bookMap) {
        if (bookObject.second.title == bookTitle) {
            if(increment){
                bookObject.second.count += count;
            }
            else{
                 bookObject.second.count -= count;
            }
        }
    }
}

int BookManager::getTotalCount() {
    int count = 0;
    for (const auto& bookObject : bookMap) {
        count += bookObject.second.count;
    }
    return count;
}
