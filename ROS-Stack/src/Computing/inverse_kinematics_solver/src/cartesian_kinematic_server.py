#!/usr/bin/env python

from __future__ import print_function

from inverse_kinematics_solver.srv import CartesianKinematicSolver,CartesianKinematicSolverResponse
import rospy
import math


FL1 = 4
FL2 = 5
FL3 = 6
FR1 = 10
FR2 = 11
FR3 = 12
BL1 = 1
BL2 = 2
BL3 = 3
BR1 = 7
BR2 = 8
BR3 = 9

def map_(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

def radToDeg(rad):
    deg = rad * 180
    deg = deg / math.pi

def degToPos(input, motor):
  if (input < 90):
      target_angle_ = 90 - input
      conv_ = (target_angle_ * 1000) / 270
      output = 500 - (conv_ * 2)
  if (input > 90):
      target_angle_ = input - 90
      conv_ = (target_angle_ * 1000) / 270
      output = (conv_ * 2) + 500
  if (input == 90):
      output = 500
  if (motor == BR1):
      output = map_(output, 0, 1000, 1000, 0)

  return int(round(output))

def handle_cartesian_kinematic_solver(req):
    print("Returning [%s, %s, %s, %s]"%(req.x, req.y, req.z, req.motor_id))
    return CartesianKinematicSolverResponse(1, 2, 3)

def inverse_kinematics_server():
    rospy.init_node('cartesian_kinematic_server')
    s = rospy.Service('cartesian_kinematic_server', CartesianKinematicSolver, handle_cartesian_kinematic_solver)
    print("Ready to compute kinematics.")
    rospy.spin()

if __name__ == "__main__":
    inverse_kinematics_server()
