#! /usr/bin/env python3
from __future__ import print_function
import rospy
import sys

from std_msgs.msg import String
# Brings in the SimpleActionClient
import actionlib
import motor_controller.msg

def fibonacci_client():
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    client = actionlib.SimpleActionClient('motor_action', motor_controller.msg.MotorAction)

    # Waits until the action server has started up and started
    # listening for goals.
    client.wait_for_server()

    # Creates a goal to send to the action server.
    goal = motor_controller.msg.MotorGoal(position=500, motor_name=String("FL_1"))

    # Sends the goal to the action server.
    client.send_goal(goal)

    # Waits for the server to finish performing the action.
    client.wait_for_result()

    # Prints out the result of executing the action
    return client.get_result()  # A FibonacciResult

if __name__ == '__main__':
    try:
        # Initializes a rospy node so that the SimpleActionClient can
        # publish and subscribe over ROS.
        rospy.init_node('fibonacci_client_py')
        result = fibonacci_client()
        print("Result:", ', '.join(result))
    except rospy.ROSInterruptException:
        print("program interrupted before completion", file=sys.stderr)