#include "vehicledashboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VehicleDashboard w;
    w.show();
    return a.exec();
}
