#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::setFlags(int value)
{    
    //setSpeedValue(ui->speed, value);
    //setDistanceValue(ui->distance, 8765);
    setLaneAssist(ui->laneAssist, true);
    setAccFlag(ui->acc,true);
    setHighOilTemp(ui->highOilTemp, true);
    setHighOilLevel(ui->highOilLevel, true);
    setLowFuel(ui->lowFuelLevel, true);
    setCheckEngine(ui->checkEngine, true);
}
