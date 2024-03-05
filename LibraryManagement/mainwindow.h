#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set>
//#include <pair>
#include "bookmanager.h"
#include "dialog.h"
#include "assignmanager.h"
#include "librarylogs.h"
#include "bookreturndialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDialog();
    void openAssignWindow();
    void updateDetails();
    void updateBookListComboBox();
    void updateTotalBookCount();
    void handleBookChange(QString const &bookName);
    void addUser();
    void openLogs();
    void openBookReturnWindow();

public slots:

private:
    Ui::MainWindow *ui;
    BookManager bookManager;
    LibraryLogs  *newLogsWindow;
    Dialog dialog;
    std::set<QString> users;
    AssignManager *assignBook;
    int totalRentedCount = 0;
    std::map<int, std::pair<QString, std::pair<QString, int>>> libraryLogsMap;
};
#endif // MAINWINDOW_H
