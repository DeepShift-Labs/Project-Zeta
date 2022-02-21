#!/usr/bin/env python

from __future__ import print_function

from inverse_kinematics_solver.srv import CartesianKinematicSolver, CartesianKinematicSolverResponse
import rospy
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


def map_(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


def radToDeg(rad):
    return (rad * 360) / (2 * math.pi)


def normalize_inverse(motor_id, position):
    final_position = position
    break_val = 0
    match motor_id:
        case FL1:
            break_val = 1
        case FR1:
            break_val = 1
        case BL1:
            break_val = 1
        case BR1:
            final_position = map(position, 0, 1000, 1000, 0);
            break_val = 1

        case FL2:
            break_val = 1
        case FR2:
            break_val = 1
        case BL2:
            break_val = 1
        case BR2:
            final_position = map(position, 0, 1000, 1000, 0);
            break_val = 1

        case FL3:
            final_position = map(position, 0, 1000, 1000, 0);
            break_val = 1
        case FR3:
            final_position = final_position - 50;
            break_val = 1
        case BL3:
            break_val = 1
        case BR3:
            final_position = map(position, 0, 1000, 1000, 0);
            break_val = 1
    return final_position;


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
    print("Returning [%s, %s, %s, %s]" % (req.x, req.y, req.z, req.motor_id))
    return CartesianKinematicSolverResponse(1, 2, 3)


def inverse_kinematics_server():
    rospy.init_node('cartesian_kinematic_server')
    s = rospy.Service('cartesian_kinematic_server', CartesianKinematicSolver, handle_cartesian_kinematic_solver)
    print("Ready to compute kinematics.")
    rospy.spin()


if __name__ == "__main__":
    inverse_kinematics_server()
