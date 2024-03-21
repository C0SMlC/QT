#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QString> locations = {"Pune", "Mumbai"};
    ui->locatiponCombobox->addItems(locations);

    connect(ui->imageSelector, &QPushButton::clicked, this, &MainWindow::selectImage);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveData);
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generatePdf);
}

void MainWindow::saveData(){

    std::string deviceName = ui->deviceNameInput->text().toStdString();
    std::string deviceSerialNumber = ui->serialNumberInput->text().toStdString();
    std::string assignee = ui->assignedInput->text().toStdString();
    std::string location = ui->locatiponCombobox->currentText().toStdString();

    if (deviceName.empty() || deviceSerialNumber.empty() || assignee.empty() || location.empty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill in all required fields.");
        return;
    }

    currentDevice = new DeviceDetails(deviceName, deviceSerialNumber, this->fileName.toStdString(), assignee, location);
    connect(this, &MainWindow::updateDetailsLog, currentDevice, &DeviceDetails::insertLogData);

    emit updateDetailsLog(*currentDevice);
}

void MainWindow::selectImage()
{
    this->fileName = QFileDialog::getOpenFileName(this, "Select An Image", QDir::homePath(), "Image Files (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        QString justFileName = fileInfo.fileName();
        ui->imageSelector->setText(justFileName);
    }
}

void MainWindow::generatePdf()
{
    if(currentDevice == nullptr){
        QMessageBox::warning(nullptr, "Error while generating the PDF", "Please save the data before attempting to generate the PDF");
        return;
    }

    QTextDocument doc;

    QString html = "<html>"
                   "<head>"
                   "<style>"
                   "body { font-family: Arial, sans-serif; }"
                   "h1 { color: #333; }"
                   "table { border-collapse: collapse; width: 100%; }"
                   "th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }"
                   "th { background-color: #f2f2f2; }"
                   "img {width: 100px; height: 100px; }"
                   "</style>"
                   "</head>"
                   "<body>"
                   "<h1>Device Information</h1>"
                   "<table>"
                   "<tr><th>Property</th><th>Value</th></tr>"
                   "<tr><td>Name</td><td>%1</td></tr>"
                   "<tr><td>Serial Number</td><td>%2</td></tr>"
                   "<tr><td colspan='2'><img src=%3 style='width: 200px; height: 200px;' /></td></tr>"
                   "</table>"
                   "</body>"
                   "</html>";

    qDebug() <<"FileName is "<<currentDevice->getFileName();

    html = html.arg(QString::fromStdString(currentDevice->getDeviceName()))
               .arg(QString::fromStdString(currentDevice->getDeviceSerialNumber()))
               .arg(QString::fromStdString(currentDevice->getFileName()));

    doc.setHtml(html);

    QString outputFilePath = QDir::currentPath() + "/output.pdf";
    qDebug() << "Output file path:" << outputFilePath;

    QPrinter printer(QPrinter::PrinterResolution);
    if (!printer.isValid()) {
        qDebug() << "Printer initialization failed";
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(outputFilePath);

    doc.print(&printer);
    qDebug() << "PDF generated successfully";
}



MainWindow::~MainWindow()
{
    delete ui;
}

