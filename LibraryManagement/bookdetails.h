#ifndef BOOKDETAILS_H
#define BOOKDETAILS_H

#include <QWidget>
#include "bookmanager.h"

namespace Ui {
class BookDetails;
}

class BookDetails : public QWidget
{
    Q_OBJECT

public:
    explicit BookDetails(BookManager& bookManager,QWidget *parent = nullptr);
    ~BookDetails();

private slots:
    void updateStackedWidget();
    void renderTable(QList<std::pair<QString, int>> list, std::string filter );

private:
    Ui::BookDetails *ui;
    BookManager& bookManager;
};

#endif // BOOKDETAILS_H
