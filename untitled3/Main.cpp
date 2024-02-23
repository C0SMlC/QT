#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget *newWidget = new QWidget;
    newWidget->setWindowTitle("My App");

    QLabel *newLabel = new QLabel("There are button below !!!");
    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");
    QPushButton *button3 = new QPushButton("Button 3");

//    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    QVBoxLayout *verticalLayout = new QVBoxLayout;

//    horizontalLayout->addWidget(button1);
//    horizontalLayout->addWidget(button2);
//    horizontalLayout->addWidget(button3);
//    newWidget->setLayout(horizontalLayout);

    verticalLayout->addWidget(newLabel);
    verticalLayout->addWidget(button1);
    verticalLayout->addWidget(button2);
    verticalLayout->addWidget(button3);

    newWidget->setLayout(verticalLayout);

    newWidget->show();

    return app.exec();
}
