void low_set() {
  ik = IK(0, 0, 26);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR3, pos2, time);

  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);

  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL3, pos2, time);
  delay(time);
}

void primitive_gait() {
  low_set();

  ik = IK(8, 0, 28);
  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR3, pos2, time);

  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);
  delay(time);


  ik = IK(15, 0, 30);
  pos = degToPos(ik.m2, BL2);
  pos1 = degToPos(ik.m1, BL1);
  pos2 = degToPos(ik.m3, BL3);
  Controller.moveServo(BL2, pos, time);
  Controller.moveServo(BL1, pos1, time);
  Controller.moveServo(BL3, pos2, time);

  pos = degToPos(ik.m2, FR2);
  pos1 = degToPos(ik.m1, FR1);
  pos2 = degToPos(ik.m3, FR3);
  Controller.moveServo(FR2, pos, time);
  Controller.moveServo(FR1, pos1, time);
  Controller.moveServo(FR3, pos2, time);
  delay(time);



  ik = IK(8, 0, 28);
  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL3, pos2, time);

  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);
  delay(time);


  ik = IK(15, 0, 30);
  pos = degToPos(ik.m2, BR2);
  pos1 = degToPos(ik.m1, BR1);
  pos2 = degToPos(ik.m3, BR3);
  Controller.moveServo(BR2, pos, time);
  Controller.moveServo(BR1, pos1, time);
  Controller.moveServo(BR3, pos2, time);

  pos = degToPos(ik.m2, FL2);
  pos1 = degToPos(ik.m1, FL1);
  pos2 = degToPos(ik.m3, FL3);
  Controller.moveServo(FL2, pos, time);
  Controller.moveServo(FL1, pos1, time);
  Controller.moveServo(FL3, pos2, time);
  delay(time);

  low_set();
}
