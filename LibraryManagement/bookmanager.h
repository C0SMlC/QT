#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H


#include <map>
#include <QString>

class BookManager {
public:

    BookManager();
    void addBook(const QString& bookTitle, const int count);
    bool removeBook(const QString& bookTitle, int count);
    int getBookCount(const QString& bookTitle);
    int getTotalCount();
    void updateBook(const QString& bookTitle, int count);
    QList<QString> getBookTitles() const;

private:
    std::map<QString, int> bookMap;
};

#endif // BOOKMANAGER_H
