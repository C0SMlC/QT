#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H


#include <map>
#include <QString>
#include "Book.h"

class BookManager {
public:

    BookManager();

    void addBook(const QString& bookTitle, const int count, const bool isTechnical);
    bool removeBook(const QString& bookTitle, int count);
    int getBookCount(const QString& bookTitle);
    int getTotalCount();
    void updateBook(const QString& bookTitle, int count,  bool increment);
    QList<QString> getBookTitles(std::string filter) const;
    QList<std::pair<QString, int>> getBooksWithCount(std::string filter);


private:
    int totalBookCount = 0;
    std::map<int, Book> bookMap;
    void createDummyData(QString const &name, int const count, bool const isTechnical);
    bool findBook(const QString& bookTitle);
    void updateCount(const Book& newBook, int count,  bool isIncrement);

};

#endif // BOOKMANAGER_H
