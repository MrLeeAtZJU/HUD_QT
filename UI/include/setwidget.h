#ifndef SETWIDGET
#define SETWIDGET
#include <QLabel>
#include "data_types.h"

enum setItems {
    ENABLE_SET = 0,
    SPEED_SET,
    DISTANCE_SET
};

#define SET_IMAGE(label, val, path) do {    \
    QPixmap pix;                            \
    if(val)  pix = QPixmap(path);			\
    else     pix.fill();			\
	label->setPixmap(pix);					\
}while(0)

#define SET_TWO_IMAGE(label, val, path1, path2) do {    \
    QPixmap pix;                                                                    \
    if(val < 0) pix = QPixmap();                                   \
    else if(val == 0) pix = QPixmap(path1);             \
    else pix = QPixmap(path2);                              \
    label->setPixmap(pix);                                      \
}while(false)

inline void setSpeedValue	 (QLabel *label1, QLabel *label2, QLabel *label3, int value) {
    value = min(999, max(0, value));
    int value1 = value / 100, value2 = value / 10 % 10, value3 = value % 10;
    QString str;
    if(value1 != 0) {
        str = "./image/speed_" + QString::number(value1) + ".png";
        SET_IMAGE(label1, 1, str);
    }
    else {
        SET_IMAGE(label1, 0, str);
    }
    std::cout << "str :" << str.toStdString() << endl;
    if(value2 != 0 || value1 != 0) {
        str = "./image/speed_" + QString::number(value2) + ".png";
        SET_IMAGE(label2, 1, str);
    }
    else {
         SET_IMAGE(label2, 0, str);
    }
    str = "./image/speed_" + QString::number(value3) + ".png";
    SET_IMAGE(label3, 1, str);
}
inline void setDistanceValue (QLabel *label1,QLabel *label2, QLabel *label3, QLabel *label4, int value)    {
    value = min(9999, max(0, value));
    int value1 = value / 1000, value2 = value / 100 % 10, value3 = value / 10 % 10, value4 = value % 10;
    QString str;
    if(value1 != 0) {
        str = "./image/distance_" + QString::number(value1) + ".png";
        SET_IMAGE(label1, 1, str);
    }
    if(value2 != 0 || value1 != 0) {
        str = "./image/distance_" + QString::number(value2) + ".png";
        SET_IMAGE(label2, 1, str);
    }
    if(value3 != 0 || value2 != 0 || value1 != 0) {
        str = "./image/distance_" + QString::number(value3) + ".png";
        SET_IMAGE(label3, 1, str);
    }
    str = "./image/distance_" + QString::number(value4) + ".png";
    SET_IMAGE(label4, 1, str);
}
inline void setLaneAssist	 (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/laneAssist.png");     }
inline void setAccFlag		 (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/accFlag.png" );       }
inline void setHighOilTemp	 (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/highOilTemp.png");    }
inline void setHighOilLevel  (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/highOilLevel.png");	  }
inline void setLowOilPressure(QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/lowOilPressure.png"); }
inline void setLowOilLevel   (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/lowOilLevel.png");   }
inline void setCriticalOil   (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/criticalLowOil.png");  }
inline void setLowFuel		 (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/lowFuel.png");        }
inline void setCheckEngine	 (QLabel *label, bool visible) { SET_IMAGE(label, visible, "./image/checkEngine.png");    }

inline void setBansOrStop(QLabel *label, short value) { SET_TWO_IMAGE(label, value, "./image/endOfAllBans.png", "./image/stopFlag.png"); }
inline void setRightFlag1(QLabel *label, short value) { SET_TWO_IMAGE(label, value, "./image/passProhibited.png", "./image/endOfProhibited.png"); }
inline void setRightFlag2(QLabel *label, short value) { SET_TWO_IMAGE(label, value, "./image/rightPass.png", "./image/rightEndOfPass.png"); }
inline void setRightFlag(QLabel *label, short value) {
    switch(value) {
    case 0:
         SET_IMAGE(label, 1, "./image/endOfAllBans.png");
        break;
    case 1:
        SET_IMAGE(label, 1, "./image/stopFlag.png");
        break;
    case 2:
        SET_IMAGE(label, 1, "./image/rightEndOfPass.png");
        break;
    case 3:
        SET_IMAGE(label, 1, "./image/passProhibited.png");
        break;
    default:
        break;
    }
}

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

inline void setLanes(QLabel *label, short value)
{
    switch (value) {
    case 0:
        SET_IMAGE(label, 1, "./image/lane0.png");
        break;
    case 1:
        SET_IMAGE(label, 1, "./image/lane1.png");
        break;
    case 2:
        SET_IMAGE(label, 1, "./image/lane2.png");
        break;
    case 3:
        SET_IMAGE(label, 1, "./image/lane3.png");
        break;
    case 4:
        SET_IMAGE(label, 1, "./image/lane4.png");
        break;
    case 5:
        SET_IMAGE(label, 1, "./image/lane5.png");
        break;
    default:
        break;
    }
}

inline void setDirection(QLabel *label, short value)
{
    switch(value) {
    case 1:
        SET_IMAGE(label, 1, "./image/directionForward1.png");
        break;
    case 2:
        SET_IMAGE(label, 1, "./image/directionForward2.png");
        break;
    default:
        break;
    }
}
#endif // SETWIDGET

