#ifndef ASSIGNMANAGER_H
#define ASSIGNMANAGER_H

#include "bookmanager.h"

#include <QWidget>
#include <set>

namespace Ui {
class AssignManager;
}

class AssignManager : public QWidget
{
    Q_OBJECT

public:
    explicit AssignManager(std::set<QString>& userSet,BookManager &bookList, int &totalLogsCount,  std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs, QWidget *parent = nullptr);
    ~AssignManager();

private slots:
    void updateDetails();
    void updateCountLable(const QString &book);


signals:
    void updateCountLabel();

private:
    Ui::AssignManager *ui;
    std::set<QString> &users;
    BookManager &books;
    std::map<int, std::pair<QString, std::pair<QString, int>>> &libraryLogs;
    int &totalLogsCount;
};

#endif // ASSIGNMANAGER_H
