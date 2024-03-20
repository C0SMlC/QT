#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>  // Corrected include
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int QGridLayoutmain(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->resize(300, 200);
    window->setWindowTitle("Minimal Qt Application");

    QLabel* label1 = new QLabel("Name: ");
    QLineEdit* input1 = new QLineEdit;

    QLabel* label2 = new QLabel("Email: ");
    QLineEdit* input2 = new QLineEdit;
    QPushButton *submitButton = new QPushButton("Submit");

    QGridLayout *newGridLayout = new QGridLayout;
    newGridLayout->addWidget(label1, 0, 0);
    newGridLayout->addWidget(input1, 0, 1);

    newGridLayout->addWidget(label2, 1, 0);
    newGridLayout->addWidget(input2, 1, 1);

    newGridLayout->addWidget(submitButton, 2, 0, 1,2);

    window->setLayout(newGridLayout);
    window->show();
    return app.exec();
}
