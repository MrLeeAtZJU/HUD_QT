#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMutex>
#include <queue>
//#include <QtNetwork/QHostAddress>
//#include <QtNetwork/QTcpSocket>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"

class Exchange;

struct CANMessage {
    int type;
    int value;
    CANMessage(int t, int v) : type(t), value(v) {}
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    static void updateSpeedValue(int value, void *handle);
    static void handleRecvCmds(int type, int value, void *handle);
	~Widget();

private slots:    
    void jumpToWorkPage();
    //void getSocketData();
    void handleRecvCmds(CarInfo& info);

private:
// data
    Ui::Widget *ui;
    Dialog1 *dialog1;
    Dialog2 *dialog2;
	Dialog3 *dialog3;
	Dialog4 *dialog4;
    QTimer *timer;
	uchar page_number;	// records the serial number of the current page
    std::queue<CANMessage> messages;
    QMutex queueMux;
//	QHostAddress hostAddress;
//	QTcpSocket client;
// function
    //void initNetwork();
    Exchange *exg;
    bool uiShowFlag;
};

#endif // WIDGET_H
