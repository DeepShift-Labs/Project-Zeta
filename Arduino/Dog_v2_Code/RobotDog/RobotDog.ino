#include <LobotServoController.h>
#include "config.h"
#include "motor_functions.h"
#include "inverse_kinematics.h"
#include "dances.h"

IK_out ik;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(9600);


  //  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, 45), time);
  //  Serial.println(pow(2, 3));
}

void loop() {
  // put your main code here, to run repeatedly:

  //  ik = IK_Solver(0, 0, 18);
  //  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  //  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);
  //
  //  delay(time + 50);
  //
  //  ik = IK_Solver(0, 0, 13);
  //  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  //  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);
  //
  //  delay(time + 50);



  ik = IK_Solver(0, -6, 18);
  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);

  delay(time + 50);

  ik = IK_Solver(0, 6, 13);
  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);

  delay(time + 50);

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
