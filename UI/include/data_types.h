#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include <iostream>
class QString;
using namespace std;
typedef unsigned char uchar;
typedef unsigned int uint;

#define GRAY_VALUE		112
#define NUM_LINES       6
#define NUM_ARROWS  5

#define HOST_ADDRESS	"127.0.0.1"
#define COM_PORT		8765
#define TCP_BUFFER_SIZE	(1024*1024)

struct CarInfo {
    short model;    // work model 1 - 4
    short bansOrStop; // -1 - No; 0 - bans; 1 - stop;
    short rightFlag1;       // -1 - No; 0 - prohibited; 1 - end of prohibited
    short rightFlag2;       // -1 - No;  0 - prohibited; 1 - end of prohibited
    short leftSlFlag1;      // positive X - cancel x km/h; negtive X - has (-X) rate-limited
    short leftSlFlag2;      // positive X - cancel x km/h; negtive X - has (-X) rate-limited
    int distanceForward;
    short directionForward;
    int speedValue;
    //bool laneLines[NUM_LINES];
    //short laneArrows[NUM_ARROWS];
    short lanesValue;
    bool checkEngin;
    bool laneAssistant;
    bool lowFuelLevel;
    bool accFlags;
    bool highOilTemp;
    short oilFlags; // -1 - No; 0 - low oil pressure; 1 - high oil level; 2 - critical oil level; 3 - low oil level
    QString roadName;
};
#endif // DATA_TYPES_H

