#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::setFlags(int value)
{    
    //setSpeedValue(ui->speed, value);
    setLaneAssist(ui->laneAssist, true);
    setAccFlag(ui->acc,true);
    setHighOilTemp(ui->highOilTemp, true);
    setHighOilLevel(ui->highOilLevel, true);
    setLowFuel(ui->lowFuelLevel, true);
    setCheckEngine(ui->checkEngine, true);
}
