#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>

#include "filtermodel.h"
#include "fluidmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    void load(QString type);
    void loadStatus(int row, int count, QString status, QString type);
    void handleValueChange();
    QTimer *timer;
    int count = 100;
};
#endif // MAINWINDOW_H
