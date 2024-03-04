#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "bookmanager.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(BookManager &manager, QWidget *parent = nullptr);
    ~Dialog();

signals:
    void updateBookListSignal();

private slots:
    void addBookToMap();
    void removeBookFromMap();

private:
    Ui::Dialog *ui;
    BookManager &bookManager;
};

#endif // DIALOG_H
