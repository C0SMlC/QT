#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QTextStream>

void read(QString filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();

    qDebug() << text;
    file.close();
}

int main() {
    QString filePath = "C:/QT/IO/file.txt";

    // 1. Ensure the directory exists
    QDir dir(QFileInfo(filePath).absolutePath());
    if (!dir.exists()) {
        if (!dir.mkpath(dir.absolutePath())) {
            qDebug() << "Failed to create directory path";
            return 1;
        }
    }

    // 2. Check if the file exists, and create it if not
    QFile file(filePath);

    if (!file.exists()) {
        qDebug() << "failed to create file";
    } else {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file for writing";
            return 1;
        }

        QTextStream out(&file);
        out << "Hello, Qt!\n";
        out << "This is some sample text. I am Pratik hetre just in case";
        file.close();
    }

    read(filePath);

    return 0;
}
