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

  //  sit(3000);
  home(3000);
  //  walk();

  IK_out ik = IK(0, 0, 20);
  int pos = degToPos(ik.m2, BR1);
  int pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  delay(3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(0, 0, 29);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  delay(3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(10, 0, 29);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  delay(3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(-10, 0, 29);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  delay(3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(0, 0, 29);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  delay(3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(-10, 0, 20);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  ik = IK(10, 0, 29);
  pos = degToPos(ik.m2, BR1);
  pos1 = degToPos(ik.m1, BR1);
  Controller.moveServo(BR2, pos, 3000);
  Controller.moveServo(BR1, pos1, 3000);
  delay(3000);

  home(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  getAllPos();
  //  delay(500);
}
