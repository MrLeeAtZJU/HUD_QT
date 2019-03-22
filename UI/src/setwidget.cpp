#include <QLabel>
#include "setwidget.h"

inline void setLeftFlag1(QLabel *label, short value)
{
    QString str;
    if(value == 0) SET_IMAGE(label, 0, "");
    else if(value > 0) str = "./image/sl_end" + QString::number(value) + ".png";
    else str = "./image/sl" + QString::number(-value) + ".png";
    SET_IMAGE(label, 1, str);
}

inline void setLeftFlag2(QLabel *label, short value)
{
    QString str;
    if(value == 0) SET_IMAGE(label, 0, "");
    else if(value > 0) str = "./image/leftsl_end" + QString::number(value) + ".png";
    else str = "./image/leftsl" + QString::number(-value) + ".png";
    SET_IMAGE(label, 1, str);
}

inline void setOilFlags(QLabel *label, short value)
{
    switch (value) {
    case 0:
        SET_IMAGE(label, 0, "");
        break;
    case 1:
        SET_IMAGE(label, 1, "./image/lowOilPressure.png");
        break;
    case 2:
        SET_IMAGE(label, 1, "./image/highOilLevel.png");
        break;
    case 3:
        SET_IMAGE(label, 1, "./image/criticalLowOil.png");
        break;
    case 4:
        SET_IMAGE(label, 1, "./image/highOilLevel.png");
        break;
    default:
        break;
    }
}
