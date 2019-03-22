#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include "data_types.h"
#include "setwidget.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    void set_lanes_and_arrows(int value);
    void handleCarInfo(CarInfo& info);
    void handleCANInfo(int type, int value);
    void InitUI();
    ~Dialog1();

private:
    Ui::Dialog1 *ui;    

private:
    // void paintEvent(QPaintEvent *event);
    // void mypaintEvent();

    // bool laneLines[NUM_LINES];
    // short laneArrows[NUM_ARROWS];
};

#endif // DIALOG1_H
