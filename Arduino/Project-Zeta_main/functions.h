void reset_motors(int duration) {
  Controller.moveServos(6, duration, FL1, 500, FL2, 500, FL3, 500, FR1, 500, FR2, 500, FR3, 500);
  delay(duration + 5);
  Controller.moveServos(6, duration, BL1, 500, BL2, 500, BL3, 500, BR1, 500, BR2, 500, BR3, 500);
  delay(duration + 5);
  Controller.moveServos(4, duration, FL2, 500, FR2, 500, BL2, 500, BR2, 500);
  delay(duration + 5);
}

void walk() {
  int duration = 3003;
  Controller.moveServos(6, duration, FL1, 500, FL2, 450, FL3, 500, FR1, 500, FR2, 750, FR3, 500);
  delay(duration + 5);
  Controller.moveServos(6, duration, BL1, 500, BL2, 250, BL3, 500, BR1, 500, BR2, 550, BR3, 500);
  delay(duration + 5);
  Controller.moveServos(4, duration, FL2, 250, FR2, 750, BL2, 250, BR2, 750);
  delay(duration + 5);
}

void home(int duration) {
  Controller.moveServos(6, duration, FL1, 500, FL2, 500, FL3, 500, FR1, 500, FR2, 500, FR3, 500);
  delay(duration / 4);
  Controller.moveServos(6, duration, BL1, 500, BL2, 500, BL3, 500, BR1, 500, BR2, 500, BR3, 500);
  delay(duration + 5);
  Controller.moveServos(4, duration, FL2, 500, FR2, 500, BL2, 500, BR2, 500);
  delay(duration + 5);
}

void sit(int duration) {
  Controller.moveServo(FL1, 0, duration);
  Controller.moveServo(FL2, 500, duration);
  Controller.moveServo(FL3, 500, duration);

  Controller.moveServo(BL1, 0, duration);
  Controller.moveServo(BL2, 500, duration);
  Controller.moveServo(BL3, 500, duration);

  Controller.moveServo(FR1, 1000, duration);
  Controller.moveServo(FR2, 500, duration);
  Controller.moveServo(FR3, 500, duration);

  Controller.moveServo(BR1, 1000, duration);
  Controller.moveServo(BR2, 500, duration);
  Controller.moveServo(BR3, 500, duration);
  delay(duration + 5);
}

int degToPos(int input, int motor) {
  double output;

  if (input < 90) {
    double target_angle_ = 90 - input;
    double conv_ = (target_angle_ * 1000) / 270;
    output = 500 - (conv_ * 2);
  }
  if (input > 90) {
    double target_angle_ = input - 90;
    double conv_ = (target_angle_ * 1000) / 270;
    output = (conv_ * 2) + 500;
  }
  if (input == 90) {
    output = 500;
  }

  if (motor == BR1) {
    output = map(output, 0, 1000, 1000, 0);
  }
  if (motor == BR2) {
    output = map(output, 0, 1000, 1000, 0);
  }
  if (motor == BR3) {
    output = map(output, 0, 1000, 1000, 0);
  }
  return int(round(output));
}

double radToDeg(double rad) {
  double deg = rad * 180;
  deg = deg / PI;
  return deg;
}

struct IK_out {
  double m1, m2, m3;
};

IK_out IK(float x, float y, float z) {

  //Up-Down Motion
  z = z - 5;
  double divisor = pow(z, 2) - pow(upper_leg_length, 2) - pow(lower_leg_length, 2);
  divisor = divisor * -1;
  double dividend = 2 * upper_leg_length * lower_leg_length;
  double quotient = divisor / dividend;
  double theta_z = acos(quotient);

  theta_z = radToDeg(theta_z);

  //Forward-Backward Motion
  x = x * -1;
  double theta_t = atan((x/z));
  theta_t = radToDeg(theta_t);
  double theta_x = 90 - theta_t;
  

  return {theta_z, theta_x, 0};
}
