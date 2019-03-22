#include "dialog4.h"
#include "ui_dialog4.h"

Dialog4::Dialog4(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dialog4::~Dialog4()
{
    delete ui;
}

void Dialog4::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix1("./image/arrow3.png");
    QPixmap pix2("./image/arrow4.png");
    QPixmap pix3("./image/lane3.png");
    QPixmap pix4("./image/lane4.png");
    QPixmap pix5("./image/lane5.png");
    int x = 135, y = 432, width = 238, height = 48;
    painter.drawPixmap(x, y, width, height, pix1);
    painter.drawPixmap(x, y, width, height, pix2);
    painter.drawPixmap(x, y, width, height, pix3);
    painter.drawPixmap(x, y, width, height, pix4);
    painter.drawPixmap(x, y, width, height, pix5);
}

void Dialog4::setFlags(int value)
{    
    QPixmap pix("./image/mapModel1.png");
    ui->map->setPixmap(pix);
    setLaneAssist(ui->laneAssist, true);
    setAccFlag(ui->acc,true);
    setHighOilTemp(ui->highOilTemp, true);
    setHighOilLevel(ui->highOilLevel, true);
    setLowFuel(ui->lowFuelLevel, true);
    setCheckEngine(ui->checkEngine, true);
}
