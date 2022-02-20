#include <LobotServoController.h>
#include "config.h"
#include "motor_functions.h"
#include "inverse_kinematics.h"
#include "dances.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(9600);

    IK_out ik = IK_Solver(0, 0, 15);
    Serial.println(radToDeg(ik.m1));
    Serial.println(radToDeg(ik.m2));
  //  Serial.println(pow(2, 3));
}

void loop() {
  // put your main code here, to run repeatedly:

  //  runMotorNormalizeInverse(FL1, 500, time);
  //  runMotorNormalizeInverse(FL2, 646, time);
  //  runMotorNormalizeInverse(FL3, 320, time);
  //
  //  runMotorNormalizeInverse(FR1, 500, time);
  //  runMotorNormalizeInverse(FR2, 500, time);
  //  runMotorNormalizeInverse(FR3, 320, time);
  //
  //  runMotorNormalizeInverse(BL1, 500, time);
  //  runMotorNormalizeInverse(BL2, 500, time);
  //  runMotorNormalizeInverse(BL3, 320, time);
  //
  //  runMotorNormalizeInverse(BR1, 500, time);
  //  runMotorNormalizeInverse(BR2, 500, time);
  //  runMotorNormalizeInverse(BR3, 320, time);
  //
  //  delay(time+50);


}
