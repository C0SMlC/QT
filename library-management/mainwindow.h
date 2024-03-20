#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Library.h"
#include "dialog.h"
#include <QMainWindow>
#include <map>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void loadBookList(QComboBox* bookList, QLabel* bookCount);
    void emitLoadBookCount(QString updatedText, QLabel* bookCount);
    void createDialog(QComboBox* bookList, QLabel* bookCount);

public slots:
    void emitLoadBookCountSlot(QString updatedText);
    void updateButtonClicked(bool value);


private:
    Ui::MainWindow *ui;
    LibraryInfo *newLibrary;
};
#endif // MAINWINDOW_H
