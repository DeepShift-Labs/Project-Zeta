#!/usr/bin/env python

from inverse_kinematics_solver.srv import CartesianKinematicSolver, CartesianKinematicSolverResponse
import math

FL1 = 1
FL2 = 12
FL3 = 3
FR1 = 11
FR2 = 10
FR3 = 2
BL1 = 5
BL2 = 6
BL3 = 4
BR1 = 7
BR2 = 9
BR3 = 8

upper_leg_length = 8; #Leg length in cm for IK
lower_leg_length = 13; #Leg length in cm for IK

def map_(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


def radToDeg(rad):
    return (rad * 360) / (2 * math.pi)


def normalize_inverse(motor_id, position):
    final_position = position
    break_val = 0
    if motor_id == FL1:
        break_val = 1
    if motor_id == FR1:
        break_val = 1
    if motor_id == BL1:
        break_val = 1
    if motor_id == BR1:
        final_position = map_(position, 0, 1000, 1000, 0)
        break_val = 1
    if motor_id == FL2:
        break_val = 1
    if motor_id == FR2:
        break_val = 1
    if motor_id == BL2:
        break_val = 1
    if motor_id == BR2:
        final_position = map_(position, 0, 1000, 1000, 0)
        break_val = 1
    if motor_id == FL3:
        final_position = map_(position, 0, 1000, 1000, 0)
        break_val = 1
    if motor_id == FR3:
        final_position = final_position - 50
        break_val = 1
    if motor_id == BL3:
        break_val = 1
    if motor_id == BR3:
        final_position = map_(position, 0, 1000, 1000, 0)
        break_val = 1
    return final_position


def degToMotorPos(motor_id, angle):
  DEGREE = 1000 / 240

  if (motor_id == FL1 or motor_id == FR1 or motor_id == BL1 or motor_id == BR1):
    if (angle > 90):
      pos = 500 + (abs(angle - 90) * DEGREE)
    
    elif (angle < 90):
      pos = 500 - (abs(angle - 90) * DEGREE)
    
    pos = round(pos)
  
  if (motor_id == FL2 or motor_id == FR2 or motor_id == BL2 or motor_id == BR2):
    if (angle > 45):
      pos = 500 - (abs(angle - 45) * DEGREE)
    elif (angle < 45):
      pos = 500 + (abs(angle - 45) * DEGREE)
    pos = round(pos)
  if (motor_id == FL3 or motor_id == FR3 or motor_id == BL3 or motor_id == BR3):
    if (angle > 90):
      pos = 500 + (abs(angle - 90) * DEGREE)
    elif (angle < 90):
      pos = 500 - (abs(angle - 90) * DEGREE)

    pos = round(pos)

  if (pos > 1000 or pos < 0):
    pos = 500

  return pos
