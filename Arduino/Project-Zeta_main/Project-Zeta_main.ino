#include <LobotServoController.h>
#include "config.h"
#include "functions.h"
//#include "serial_servo.h"



void setup() {
  if (Debug != 1) {
    pinMode(13, OUTPUT);
  }
  if (Debug != 1) {
    digitalWrite(13, LOW);
  }
  else if (Debug == 1) {
    digitalWrite(13, HIGH);
  }

  Serial.begin(57600);
  Serial1.begin(9600);
  Serial2.begin(115200);

  delay(1000);

  reset_motors(3000);
  home(3000);
  delay(3000);

  //low_set();

  //up stroke 1
  ik = IK(4, 0, 22);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);
  delay(time/3);

  ik = IK(4, 0, 27);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);

  //down stroke 1
  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);


  //Back stroke 1
  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);




  //up stroke 2
  ik = IK(4, 0, 22);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);
  delay(time/3);

  ik = IK(4, 0, 27);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);

  //down stroke 2
  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);


  //Back stroke 2
  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);
  

}

void loop() {
  //up stroke 1
  ik = IK(4, 0, 23);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);
  delay(time/3);

  ik = IK(4, 0, 27);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);

  //down stroke 1
  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);


  //Back stroke 1
  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);




  //up stroke 2
  ik = IK(4, 0, 23);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);
  delay(time/3);

  ik = IK(4, 0, 27);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);

  //down stroke 2
  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(6, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);


  //Back stroke 2
  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR3, pos2, time);

  ik = IK(-6, 0, 28);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL3, pos2, time);

  ik = IK(0, 0, 28);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);
}
