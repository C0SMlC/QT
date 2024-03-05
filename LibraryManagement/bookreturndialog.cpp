#include "bookreturndialog.h"
#include "ui_bookreturndialog.h"

#include <QMessageBox>

BookReturnDialog::BookReturnDialog(std::map<int, std::pair<QString, std::pair<QString, int>>>& logs,BookManager& books,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookReturnDialog),
    libraryLogs(logs),
    booksList(books)
{
    ui->setupUi(this);

    qDebug() << booksList.getBookTitles();
    QList<QString> users;

    for(auto const& it: libraryLogs){
        qDebug() << it.second.second.first;
        users.append(it.second.second.first);
    }

    if(users.empty()){
        QMessageBox::information(nullptr, "Error!", "No Logs Added!");
        return;
    }else{
        ui->comboBox->addItems(users);
    }

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &BookReturnDialog::updateValues);
}

void BookReturnDialog::updateValues(QString const& value){
    for(auto const &it:libraryLogs){
        if(it.second.second.first == value){
            ui->bookNameBox->setText(it.second.first);
            ui->bookCountBox->setText(QString::number(it.second.second.second));
        }
    }
};

BookReturnDialog::~BookReturnDialog()
{
    delete ui;
}
