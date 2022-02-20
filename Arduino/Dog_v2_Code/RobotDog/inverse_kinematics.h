struct IK_out {
  double m1, m2, m3;
};

IK_out IK_Solver(float x, float y, float z){
  y = y * -1;

  float z_alt = sqrt(sq(y)+sq(z));

  
  double numerator_b = pow(z_alt, 2) - pow(upper_leg_length, 2) - pow(lower_leg_length, 2);
  double denominator_b = (-2)*upper_leg_length*lower_leg_length;
  double theta_lower = acos(numerator_b/denominator_b);
  
  double numerator_u = lower_leg_length*sin(theta_lower);
  double theta_upper = asin(numerator_u/z_alt);

  double mid_angle = atan(y/z);
  double final_theta_upper = PI-(PI/2)-theta_upper-mid_angle;

  double theta_joint_3 = (PI/2) - atan(x/z);

  return {theta_lower, final_theta_upper, theta_joint_3};
}
