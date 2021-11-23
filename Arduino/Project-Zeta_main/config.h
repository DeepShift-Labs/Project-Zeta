#define FL1 4
#define FL2 5
#define FL3 6
#define FR1 10
#define FR2 11
#define FR3 12
#define BL1 1
#define BL2 2
#define BL3 3
#define BR1 7
#define BR2 8
#define BR3 9

#define Debug 1

LobotServoController Controller(Serial1);

float upper_leg_length = 16.5; //cm
float lower_leg_length = 19.5; //cm

const int time = 700;
