from __future__ import print_function

import sys, time
import serial
import lewansoul_lx16a
from math_libs import *

import rospy
from inverse_kinematics_solver.srv import *

SERIAL_PORT = '/dev/motor_controller'    # For Linux

#ctrl = lewansoul_lx16a.ServoController(
#    serial.Serial(SERIAL_PORT, 115200, timeout=1),
#)


def kinematics_solver_client(x, y, z, id):
    rospy.wait_for_service('cartesian_kinematic_server')
    try:
        kinematics_solver = rospy.ServiceProxy('cartesian_kinematic_server', CartesianKinematicSolver)
        resp1 = kinematics_solver(x, y, z, id)
        return resp1.angle_1, resp1.angle_2, resp1.angle_3
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)


def servo_info(id):
    print("Servo id: {}".format(id))
    print("Position: {}".format(ctrl.get_position(id)))
    print("Temperature: {}".format(ctrl.get_temperature(id)))


def convert_values(motor_id, init_val):
    final_val = radToDeg(init_val)
    final_val = degToMotorPos(motor_id, final_val)
    final_val = normalize_inverse(motor_id, final_val)
    return final_val


if __name__ == '__main__':
    x=0
    y=0
    z=18
    id=1
    print("Requesting %s, %s, %s, %s"%(x, y, z, id))
    x_t, y_t, z_t = kinematics_solver_client(x, y, z, id)
    print(f"Response: {(x_t, y_t, z_t)}")
    print(convert_values(id, x_t))
