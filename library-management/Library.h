#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>
#include <QString>
#include <QObject>
#include <QComboBox>
#include <QLabel>

class LibraryInfo:public QObject{
Q_OBJECT

public:
    LibraryInfo();
    ~LibraryInfo();

public slots:
    void loadBooks(QComboBox* bookList, QLabel *bookCount);
    void updateCount(QString updatedText, QLabel *bookCount);
    void insertBookSlot(QComboBox* bookList, QLabel *bookCount, QString bookName, int numOfBooks);

signals:
    void booksUpdated(QComboBox* bookList, QLabel *bookCount);

private:
    std::map <QString, int> *bookMap;
    QComboBox* bookList;
    QLabel *bookCount;
    int bookCountNumber;
};

#endif // LIBRARY_H
