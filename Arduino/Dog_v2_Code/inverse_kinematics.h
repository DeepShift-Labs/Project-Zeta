struct IK_out {
  double m1, m2, m3;
};

IK_out IK_Solver(float x, float y, float z){
  double numerator_b = pow(z, 2) - pow(upper_leg_length, 2) - pow(lower_leg_length, 2);
  double denominator_b = (-2)*upper_leg_length*lower_leg_length;
  double theta_lower = acos(numerator_b/denominator_b);
  
  double numerator_u = lower_leg_length*sin(theta_lower);
  double theta_upper = asin(numerator_u/z);

  return {theta_lower, theta_upper, 1};
}
