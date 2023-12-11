#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>

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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    do_cpp();

    do_QT();

    return a.exec();
}
