#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <exchange.h>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
	this->hide();
    // initialize private data members
	page_number  = 0;	// main page
    uiShowFlag = true;
    dialog1 = new Dialog1();
	dialog2 = new Dialog2();
	dialog3 = new Dialog3();
	dialog4 = new Dialog4();
    timer = new QTimer(this);
    // execute initialized operations
//	initNetwork();
    exg = new Exchange();
    exg->RegRefreshUIFunc(handleRecvCmds, (void*)this);
    //ui->setupUi(this);
	dialog1->show();
//	page_number++;
   timer->start(200);
    connect( timer, SIGNAL( timeout() ), this, SLOT( jumpToWorkPage() ) );
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete timer;
    delete dialog1;
	delete dialog2;
	delete dialog3;
	delete dialog4;
    delete ui;
}

void Widget::jumpToWorkPage()
{
	CarInfo info;
    int speedValue[25] = { -110, -100, -90, -80, -70, -60, -50, -40, -30, -20, -10, -5, 0, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 };
	info.model = 1;
    info.bansOrStop = rand() % 3 - 1;
    info.rightFlag1 = rand() % 4;
    info.rightFlag2 = rand() % 3 - 1;
    info.leftSlFlag1 = speedValue[rand() % 25];
    info.leftSlFlag2 = speedValue[rand() % 25];
 //   info.distanceForward = rand() % 1000;
    info.directionForward = rand() % 2 + 1;
//    info.speedValue = rand() % 200;
    QString roadName[] = {"Binsheng road", "Jiangnan avenue", "Changhe road", "Weiye road"};
    info.roadName = roadName[rand() % 4];
//    info.laneLines[0] = rand() % 2;
//    info.laneLines[1] = rand() % 2;
//    info.laneLines[2] = rand() % 2;
//    info.laneLines[3] = rand() % 2;
//    info.laneLines[4] = rand() % 2;
//    info.laneLines[5] = rand() % 2;
//    info.laneArrows[0] = rand() % 2;
//    info.laneArrows[1] = rand() % 2;
//    info.laneArrows[2] = rand() % 2;
//    info.laneArrows[3] = rand() % 2;
//    info.laneArrows[4] = rand() % 2;
    info.lanesValue = rand() % 6;
    info.checkEngin = rand() % 2;
    info.laneAssistant = rand() % 2;
    info.lowFuelLevel = rand() % 2;
    info.accFlags = rand() % 2;
    info.highOilTemp = rand() % 2;
    info.oilFlags = rand() % 5;

    queueMux.lock();
    while(!messages.empty()) {
        CANMessage &mes = messages.front();
        if(uiShowFlag) {
            dialog1->handleCANInfo(mes.type, mes.value);
        }
        if(mes.type == ENABLE_SET) {
            if(mes.value == 0) uiShowFlag = false;
            else {
                uiShowFlag = true;
                dialog1->InitUI();
            }
        }
      messages.pop();
    }
    queueMux.unlock();

    if(uiShowFlag) 	handleRecvCmds(info);


/*	switch(page_number) {
		case 0: // main page
			this->show();
			dialog1->hide();
			dialog2->hide();
			dialog3->hide();
			dialog4->hide();
			break;
		case 1:	// Model 1
			dialog1->set_lanes_and_arrows(165);
			dialog1->show();
			this->hide();
			dialog2->hide();
			dialog3->hide();
			dialog4->hide();
			break;
		case 2:	// Model 2
			dialog2->setFlags(291);
			dialog2->show();
			this->hide();
			dialog1->hide();
			dialog3->hide();
			dialog4->hide();
			break;
		case 3: // Model 3
			dialog3->setFlags(765);
			dialog3->show();
			this->hide();
			dialog1->hide();
			dialog2->hide();
			dialog4->hide();
			break;
		case 4: // Model 4
			dialog4->setFlags(179);
			dialog4->show();
			this->hide();
			dialog1->hide();
			dialog2->hide();
			dialog3->hide();
			break;
		default:
			cout << "Exception: There is something wrong about page sequence." << endl;
			break;
	}
	if(page_number == 4) page_number = 1;
	else				 page_number++;*/
}

void Widget::handleRecvCmds(CarInfo& info)
{
    switch (info.model) {
    case 1:
        dialog1->show();
        dialog1->handleCarInfo(info);
        this->hide();
        dialog2->hide();
        dialog3->hide();
        dialog4->hide();
        break;
    default:
        break;
    }
}

void Widget::handleRecvCmds(int type, int value, void *handle)
{
    Widget* pwgt = (Widget*)handle;
    pwgt->queueMux.lock();
    pwgt->messages.push(CANMessage(type, value));
    pwgt->queueMux.unlock();
}
