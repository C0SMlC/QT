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

private:
    Ui::addOperatorDialog *ui;
};

#endif // ADDOPERATORDIALOG_H
