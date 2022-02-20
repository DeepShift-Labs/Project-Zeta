<<<<<<< HEAD:Arduino/DEPRECATED_Project-Zeta_main/config.h
// Motor ID definitions
//FL1 - Front-Left-1
//1 - Foot; 2 - Knee; 3 - Hip
=======
//Define Motor IDs
>>>>>>> main:Arduino/Project-Zeta_main/config.h
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
<<<<<<< HEAD:Arduino/DEPRECATED_Project-Zeta_main/config.h
//End of  motor ID definitions

#define Debug 1 //Enable Debug

LobotServoController Controller(Serial1); // Create Servo Controller Object

float upper_leg_length = 16.5; //Leg length in cm for IK
float lower_leg_length = 19.5; //Leg length in cm for IK

const int time = 700; //Time per motor move command
=======
//END Define Motor IDs

//Enable Debug
#define Debug 1

//Instantiate Servo Controller
LobotServoController Controller(Serial1);

//Lengths of the legs(from center of rotation) to compute IK
float upper_leg_length = 16.5; //cm
float lower_leg_length = 19.5; //cm

//Time per move
const int time = 500;
>>>>>>> main:Arduino/Project-Zeta_main/config.h
