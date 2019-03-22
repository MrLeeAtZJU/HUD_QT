#include "dialog1.h"
#include "ui_dialog1.h"
#include <QString>

Dialog1::Dialog1(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog1)
{    
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->leftSlFlag1->setAttribute(Qt::WA_TranslucentBackground);
    // ui->leftSlFlag2->setAttribute(Qt::WA_TranslucentBackground);
    ui->rightFlag1->setAttribute(Qt::WA_TranslucentBackground);
    // ui->rightFlag2->setAttribute(Qt::WA_TranslucentBackground);
    // ui->colorLine->setAttribute(Qt::WA_TranslucentBackground);
    // ui->dotFlag->setAttribute(Qt::WA_TranslucentBackground);
    InitUI();
}

void Dialog1::InitUI() {
    SET_IMAGE(ui->colorLine, 1, "./image/colorLine.png");
    // SET_IMAGE(ui->dotFlag, 1, "./image/dotFlag.png");
    SET_IMAGE(ui->directionForward, 1, "./image/directionForward1.png");
    SET_IMAGE(ui->distanceUnit, 1, "./image/distanceUnit.png");
    SET_IMAGE(ui->speedUnit, 1, "./image/speedUnit.png");
    SET_IMAGE(ui->borderRect, 1, "./image/borderRect.png");
    setSpeedValue(ui->speed1, ui->speed2, ui->speed3, 0);
    setDistanceValue(ui->distance1, ui->distance2, ui->distance3, ui->distance4, 0);
}

Dialog1::~Dialog1()
{    
    delete ui;
}
/*
void Dialog1::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QString str;
    QPixmap pix;
    const int x = 217, y = 334, width = 167, height = 35;
    for(int i = 0; i < NUM_LINES; i++) {
        str = "./image/lane" + QString::number(i + 1) + ".png";
        pix = QPixmap(str);
        if(laneLines[i]) painter.drawPixmap(x, y, width, height, pix);
    }
    for(int i = 0; i < NUM_ARROWS; i++) {
        str = "./image/arrow" + QString::number(i + 1) + ".png";
        pix = QPixmap(str);
        if(laneArrows[i]) painter.drawPixmap(x, y, width, height, pix);
    }
}*/

void Dialog1::handleCarInfo(CarInfo &info)
{
    // memcpy(laneLines, info.laneLines, 6 * sizeof(bool));
    // memcpy(laneArrows, info.laneArrows, 5 * sizeof(short));
    // this->repaint();
    //setBansOrStop(ui->bansOrStop, info.bansOrStop);
    setRightFlag(ui->rightFlag1, info.rightFlag1);
    setLeftFlag1(ui->leftSlFlag1, info.leftSlFlag1);
    setLeftFlag2(ui->leftSlFlag2, info.leftSlFlag2);
   // setDistanceValue(ui->distance1, ui->distance2, ui->distance3, ui->distance4, 3590);
   // setSpeedValue(ui->speed1, ui->speed2, ui->speed3, info.speedValue);
    //setLanes(ui->lanes, info.lanesValue);
    setDirection(ui->directionForward, info.directionForward);
    ui->roadName->setText(info.roadName);
   // setCheckEngine(ui->checkEngine, info.checkEngin);
   // setLaneAssist(ui->laneAssist, info.laneAssistant);
   // setLowFuel(ui->lowFuelLevel, info.lowFuelLevel);
   // setAccFlag(ui->acc, info.accFlags);
   // setHighOilTemp(ui->highOilTemp, info.highOilTemp);
   // setOilFlags(ui->highOilLevel, info.oilFlags);
}

void Dialog1::handleCANInfo(int type, int value)
{
    switch(type) {
    case ENABLE_SET:
        SET_IMAGE(ui->borderRect, 0, "");
        SET_IMAGE(ui->colorLine, 0, "");
        SET_IMAGE(ui->directionForward, 0, "");
        SET_IMAGE(ui->distance1, 0, "");
        SET_IMAGE(ui->distance2, 0, "");
        SET_IMAGE(ui->distance3, 0, "");
        SET_IMAGE(ui->distance4, 0, "");
        SET_IMAGE(ui->distanceUnit, 0, "");
        SET_IMAGE(ui->leftSlFlag1, 0, "");
        SET_IMAGE(ui->leftSlFlag2, 0, "");
        SET_IMAGE(ui->rightFlag1, 0, "");
        SET_IMAGE(ui->roadName, 0, "");
        SET_IMAGE(ui->speed1, 0, "");
        SET_IMAGE(ui->speed2, 0, "");
        SET_IMAGE(ui->speed3, 0, "");
        SET_IMAGE(ui->speedUnit, 0, "");
        break;
    case SPEED_SET:
      //  setSpeedValue(ui->speed, value);
        setSpeedValue(ui->speed1, ui->speed2, ui->speed3, value);
        break;
    case DISTANCE_SET:
        setDistanceValue(ui->distance1, ui->distance2, ui->distance3, ui->distance4, value);
        break;
    default:
        break;
    }
}

void Dialog1::set_lanes_and_arrows(int value)
{
    QPixmap pix("./image/mapModel1.png");
   // setSpeedValue(ui->speed, value);
   // setDistanceValue(ui->distance, 8765);
    // setLaneAssist(ui->laneAssist, true);
    // setAccFlag(ui->acc,true);
    // setHighOilTemp(ui->highOilTemp, true);
    // setHighOilLevel(ui->highOilLevel, true);
    // setLowFuel(ui->lowFuelLevel, true);
    // setCheckEngine(ui->checkEngine, true);
    cout << "in function set_lanes_and_arrows" << endl;
}
