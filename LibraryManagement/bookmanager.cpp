#include <QList>

#include "bookmanager.h"

BookManager::BookManager() {
    bookMap["C++"] = 10;
    bookMap["Linux"] = 5;
}


void BookManager::addBook(const QString& bookTitle, const int count) {
    auto it = bookMap.find(bookTitle);
    if(it == bookMap.end()){
        bookMap[bookTitle] = count;
    }else{
        bookMap[bookTitle] =  bookMap[bookTitle] + count;
    }
}

bool BookManager::removeBook(const QString& bookTitle, int count) {
    auto it = bookMap.find(bookTitle);
    if (it != bookMap.end()) {
        if (it->second >= count) {
            it->second -= count;
            if (it->second == 0) {
                bookMap.erase(it);
            }
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int BookManager::getBookCount(const QString& bookTitle) {
    return bookMap.count(bookTitle) > 0 ? bookMap[bookTitle] : 0;
}

QList<QString> BookManager::getBookTitles() const {
    QList<QString> titles;
    for (const auto& entry : bookMap) {
        titles.append(entry.first);
    }
    return titles;
}

void BookManager::updateBook(const QString& bookTitle, int count){
    auto it = bookMap.find(bookTitle);
    if(it == bookMap.end()){
        return;
    }

    bookMap[bookTitle]=bookMap[bookTitle] - count;
    return;
}

int BookManager::getTotalCount(){
    int count = 0;
    for(auto const &it:bookMap){
        count += it.second;
    }
    return count;
}
