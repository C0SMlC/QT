#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

int BOXLAYOUTmain(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->resize(800, 500);
    window->setWindowTitle("Minimal Qt Application");
    window->show();

    QPushButton* button1 = new QPushButton("Click Me");
    QPushButton* button2 = new QPushButton("Click Me");
    QPushButton* button3 = new QPushButton("Click Me");

//    QHBoxLayout *newHorizontalLayout = new QHBoxLayout;
//    newHorizontalLayout->addWidget(button1);
//    newHorizontalLayout->addWidget(button2);
//    newHorizontalLayout->addWidget(button3);
//    window->setLayout(newHorizontalLayout);


    QVBoxLayout *newVerticalLayout = new QVBoxLayout;
    newVerticalLayout->addWidget(button1);
    newVerticalLayout->addWidget(button2);
    newVerticalLayout->addWidget(button3);
    window->setLayout(newVerticalLayout);
    return app.exec();
}
