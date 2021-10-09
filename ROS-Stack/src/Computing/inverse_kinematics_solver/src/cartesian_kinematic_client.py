#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from inverse_kinematics_solver.srv import *

def kinematics_solver_client(x, y, z, id):
    rospy.wait_for_service('cartesian_kinematic_server')
    try:
        kinematics_solver = rospy.ServiceProxy('cartesian_kinematic_server', CartesianKinematicSolver)
        resp1 = kinematics_solver(x, y, z, id)
        return resp1.angle_1, resp1.angle_2, resp1.angle_3
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "%s [x y z id]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 5:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
        z = float(sys.argv[3])
        id = int(sys.argv[4])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting %s+%s+%s+%s"%(x, y, z, id))
    print("%s + %s + %s + %s = %s"%(x, y, z, id, kinematics_solver_client(x, y, z, id)))
