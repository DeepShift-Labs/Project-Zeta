// Motor ID definitions
//FL1 - Front-Left-1
//1 - Foot; 2 - Knee; 3 - Hip
#define FL1 1
#define FL2 12
#define FL3 3
#define FR1 11
#define FR2 10
#define FR3 2
#define BL1 5
#define BL2 6
#define BL3 4
#define BR1 7
#define BR2 9
#define BR3 8
//End of  motor ID definitions

#define Debug 1 //Enable Debug

LobotServoController Controller(Serial1); // Create Servo Controller Object

float upper_leg_length = 8; //Leg length in cm for IK
float lower_leg_length = 13; //Leg length in cm for IK

const int time = 3000; //Time per motor move command

//MAX Definitions
const int motor_1_MIN = 320;
const int motor_1_MAX = 1000;

const int motor_2_MIN = 320;
const int motor_2_MAX = 870;

const int motor_3_MIN = 0;
const int motor_3_MAX = 750;
