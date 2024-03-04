#ifndef LIBRARYLOGS_H
#define LIBRARYLOGS_H

#include <QWidget>
#include <map>

namespace Ui {
class LibraryLogs;
}

class LibraryLogs : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryLogs(std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs,int &totalLogsCount, QWidget *parent = nullptr);
    ~LibraryLogs();


private:
    Ui::LibraryLogs *ui;
    std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs;
    int &totalLogsCount;
};

#endif // LIBRARYLOGS_H
