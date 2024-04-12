#ifndef ADDOPERATORDIALOG_H
#define ADDOPERATORDIALOG_H

#include <QDialog>

namespace Ui {
class addOperatorDialog;
}

class addOperatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addOperatorDialog(QWidget *parent = nullptr);
    ~addOperatorDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addOperatorDialog *ui;

signals:
    void addUserSignal(const QString& userName);
};

#endif // ADDOPERATORDIALOG_H
