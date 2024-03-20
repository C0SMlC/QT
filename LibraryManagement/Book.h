#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
public:
    QString title;
    bool isTechnical;
    int count;


    Book(const QString& title, bool isTechnical, int count)
        : title(title), isTechnical(isTechnical), count(count) {}

    bool operator<(const Book& other) const {
        if (title != other.title) {
            return title < other.title;
        }
        return false;
    }
};

#endif // BOOK_H
