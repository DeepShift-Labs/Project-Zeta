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



  runMotorNormalizeInverse(FL1, 500, time);
  runMotorNormalizeInverse(FL2, 500, time);
  runMotorNormalizeInverse(FL3, 500, time);

  runMotorNormalizeInverse(FR1, 500, time);
  runMotorNormalizeInverse(FR2, 500, time);
  runMotorNormalizeInverse(FR3, 500, time);

  runMotorNormalizeInverse(BL1, 500, time);
  runMotorNormalizeInverse(BL2, 500, time);
  runMotorNormalizeInverse(BL3, 500, time);
  //
  runMotorNormalizeInverse(BR1, 500, time);
  runMotorNormalizeInverse(BR2, 500, time);
  runMotorNormalizeInverse(BR3, 500, time);

  //    Controller.moveServo(BR1, 500, time);
  //    Controller.moveServo(BR2, 500, time);
  //    Controller.moveServo(BR3, 500, time);

  delay(time + 1000);

  //      runMotorNormalizeInverse(BL3, degToMotorPos(BL3, 120), time);
  //  Serial.println(pow(2, 3));
}

void loop() {
  // put your main code here, to run repeatedly:
  ik = IK_Solver(0, 0, 13);
  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(FL3, degToMotorPos(FL3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 13);
  runMotorNormalizeInverse(FR1, degToMotorPos(FR1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FR2, degToMotorPos(FR2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(FR3, degToMotorPos(FR3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 13);
  runMotorNormalizeInverse(BL1, degToMotorPos(BL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(BL2, degToMotorPos(BL2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(BL3, degToMotorPos(BL3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 13);
  runMotorNormalizeInverse(BR1, degToMotorPos(BR1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(BR2, degToMotorPos(BR2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(BR3, degToMotorPos(BR3, radToDeg(ik.m3)), time);
  delay(time + 50);




  ik = IK_Solver(0, 0, 18);
  runMotorNormalizeInverse(FL1, degToMotorPos(FL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FL2, degToMotorPos(FL2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(FL3, degToMotorPos(FL3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 18);
  runMotorNormalizeInverse(FR1, degToMotorPos(FR1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(FR2, degToMotorPos(FR2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(FR3, degToMotorPos(FR3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 18);
  runMotorNormalizeInverse(BL1, degToMotorPos(BL1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(BL2, degToMotorPos(BL2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(BL3, degToMotorPos(BL3, radToDeg(ik.m3)), time);

  ik = IK_Solver(0, 0, 18);
  runMotorNormalizeInverse(BR1, degToMotorPos(BR1, radToDeg(ik.m1)), time);
  runMotorNormalizeInverse(BR2, degToMotorPos(BR2, radToDeg(ik.m2)), time);
  runMotorNormalizeInverse(BR3, degToMotorPos(BR3, radToDeg(ik.m3)), time);
  delay(time + 50);

  //  swivel(time);
}
