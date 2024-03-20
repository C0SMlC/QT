//#include <QtCore/QCoreApplication>
//#include <QApplication>
//#include <QDebug>
//#include <QDir>
//#include <QFileInfo>

//int main(int argc, char *argv[]) {
//    QCoreApplication app(argc, argv);
////    QString folderPath = "NonExistingDir";

////    QDir mdir("E:/");
////    foreach(QFileInfo mItm, mdir.drives()){
////        qDebug() << mItm.absoluteFilePath();
////        qDebug() << (mItm.absoluteFilePath() + folderPath);
////        mdir.mkpath(mItm.absoluteFilePath()  + folderPath);
////    }


//    QDir mtdir("E:/NonExistingDir");
//    foreach(QFileInfo item, mtdir.entryInfoList()){
//        qDebug() << item.absoluteFilePath();
//    }


////    QDir directory;

////    if(directory.exists(folderPath)){
////        directory.rmdir(folderPath);
////        qDebug()<< "Directory Existed and removed...";
////    }else{
////        directory.mkpath(folderPath);
////        qDebug()<< "Directory Created";
////    }

//    return app.exec();
//}

#include <QDir>
#include <QDebug>
#include <QFileInfo>

int hiihh() {
    QString DirectoryName = "E:/";
    QDir directory(DirectoryName);

    foreach(QFileInfo item,directory.entryInfoList()){
        qDebug() << item.absoluteFilePath();
    }
}
