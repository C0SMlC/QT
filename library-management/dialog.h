#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Library.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void createNewDialog(QComboBox* bookList, QLabel* bookCount);
    void throwInsertSignal(bool value);

signals:
    void insertBookSignal(QComboBox* bookList, QLabel* bookCount, QString bookName, int numOfBook );
    void loadBooks();

private:
    Ui::Dialog *ui;
    Dialog *newDialog;
    QComboBox* bookList = nullptr;
    QLabel* bookCount= nullptr;
};

#endif // DIALOG_H
