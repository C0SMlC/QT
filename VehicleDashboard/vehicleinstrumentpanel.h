#ifndef VEHICLEINSTRUMENTPANEL_H
#define VEHICLEINSTRUMENTPANEL_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class VehicleInstrumentPanel;
}

class VehicleInstrumentPanel : public QWidget
{
    Q_OBJECT

public:
    explicit VehicleInstrumentPanel(QWidget *parent = nullptr);
    ~VehicleInstrumentPanel();

private:
    QTimer* increaseSpeedTimer;
    Ui::VehicleInstrumentPanel *ui;
    int speed = 20;
public slots:
    void increaseSpeed();
};

#endif // VEHICLEINSTRUMENTPANEL_H
