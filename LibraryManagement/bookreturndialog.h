#ifndef BOOKRETURNDIALOG_H
#define BOOKRETURNDIALOG_H

#include <QDialog>
#include "bookmanager.h"
#include <map>

namespace Ui {
class BookReturnDialog;
}

class BookReturnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookReturnDialog(std::map<int, std::pair<QString, std::pair<QString, int>>>& logs,BookManager& books ,QWidget *parent = nullptr);
    ~BookReturnDialog();

private slots:
    void updateValues(QString const& value);
    void updateBooksComboBox(const QString& userName);
    void updateLibrary();

signals:
    void updateCountLabel();

private:
    std::map<int, std::pair<QString, std::pair<QString, int>>>& libraryLogs;
    BookManager& booksList;
    int logId;
    int bookCount;
    int totalBorrowedCount;
    QString bookName;
    Ui::BookReturnDialog *ui;
};

#endif // BOOKRETURNDIALOG_H
