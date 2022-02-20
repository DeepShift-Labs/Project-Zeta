// Motor ID definitions
//FL1 - Front-Left-1
//1 - Foot; 2 - Knee; 3 - Hip
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
//End of  motor ID definitions

#define Debug 1 //Enable Debug

LobotServoController Controller(Serial1); // Create Servo Controller Object

float upper_leg_length = 16.5; //Leg length in cm for IK
float lower_leg_length = 19.5; //Leg length in cm for IK

const int time = 700; //Time per motor move command
