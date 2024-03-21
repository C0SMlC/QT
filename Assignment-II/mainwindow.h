#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "DeviceDetails.h"
//#include "DBService.h"

#include <QMessagebox>
#include <QPdfWriter>
#include <QtPrintSupport/QPrinter>
#include <QtGui/QTextDocument>
#include <QFileDialog>

#include "services/service.h"

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
    void updateDetailsLog(const DeviceDetails& newLog);

private slots:
    void selectImage();
    void saveData();
    void generatePdf();

private:
    Ui::MainWindow *ui;
    QString fileName;
    DeviceDetails *currentDevice = nullptr;
};
#endif // MAINWINDOW_H
