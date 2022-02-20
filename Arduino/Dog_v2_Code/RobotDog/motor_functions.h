int normalize_inverse(int motor_id, int position) {
  int final_position = position;
  switch (motor_id) {
    case FL1:
      break;
    case FR1:
      break;
    case BL1:
      break;
    case BR1:
      final_position = map(position, 0, 1000, 1000, 0);
      break;

    case FL2:
      break;
    case FR2:
      break;
    case BL2:
      break;
    case BR2:
      final_position = map(position, 0, 1000, 1000, 0);
      break;

    case FL3:
      final_position = map(position, 0, 1000, 1000, 0);
      break;
    case FR3:
      final_position = final_position - 50;
      break;
    case BL3:
      break;
    case BR3:
      final_position = map(position, 0, 1000, 1000, 0);
      break;
  }
  return final_position;
}

void runMotorNormalizeInverse(int motor_id, int position, int time) {
  Controller.moveServo(motor_id, normalize_inverse(motor_id, position), time);
}

int degToMotorPos(int motor_id, double angle) {
  double pos;
  float DEGREE = 1000 / 240;

  if (motor_id == FL1 || motor_id == FR1 || motor_id == BL1 || motor_id == BR1) {
    if (angle > 90) {
      pos = 500 + (abs(angle - 90) * DEGREE);
    }
    else if (angle < 90) {
      pos = 500 - (abs(angle - 90) * DEGREE);
    }
    pos = round(pos);
  }
  if (motor_id == FL2 || motor_id == FR2 || motor_id == BL2 || motor_id == BR2) {
    if (angle > 45) {
      pos = 500 - (abs(angle - 45) * DEGREE);
    }
    else if (angle < 45) {
      pos = 500 + (abs(angle - 45) * DEGREE);
    }
    pos = round(pos);
  }
  if (motor_id == FL3 || motor_id == FR3 || motor_id == BL3 || motor_id == BR3) {
    if (angle > 90) {
      pos = 500 + (abs(angle - 90) * DEGREE);
    }
    else if (angle < 90) {
      pos = 500 - (abs(angle - 90) * DEGREE);
    }
    pos = round(pos);
  }

  if (pos > 1000 || pos < 0) {
    pos = 500;
  }
  return pos;
}

double radToDeg(double rad){
  return (rad*360)/(2*PI);
}
