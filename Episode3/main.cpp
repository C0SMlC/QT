#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>

#include <QDebug>

using namespace std;

void do_cpp(){
    string name;
    cout<<"Please enter your name: "<<endl;
    getline(cin,name);
    cout<<"Hello"<<" "<<name<<endl;
}

void do_QT(){

    QTextStream input(stdin);
    QTextStream output(stdout);

    output << "Please enter QT your name: "<<"\n";
    output.flush();
    QString name = input.readLine();
    output << "Hello " << name<<"\n";
    output.flush();

}

void do_mixed(){
    QTextStream input(stdin);
    qInfo()<< "Please enter your name - ";
    QString name = input.readLine();
    qInfo()<< "My name is "<<name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_cpp();
    do_QT();
    do_mixed();

    return a.exec();
}
