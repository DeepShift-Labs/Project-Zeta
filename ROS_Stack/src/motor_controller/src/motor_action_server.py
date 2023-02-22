#! /usr/bin/env python3

"""
import rospy
import actionlib
import motor_controller.msg
from std_msgs.msg import Float64

class MotorAction(object):
    # create messages that are used to publish feedback/result
    _feedback = motor_controller.msg.MotorFeedback()
    _result = motor_controller.msg.MotorResult()

    motors = [['FL_1_position_controller', 'FL_2_position_controller', 'FL_3_position_controller'],
              ['FR_1_position_controller', 'FR_2_position_controller', 'FR_3_position_controller'],
              ['BL_1_position_controller', 'BL_2_position_controller', 'BL_3_position_controller'],
              ['BR_1_position_controller', 'BR_2_position_controller', 'BR_3_position_controller']]
    publishers = [[None, None, None], [None, None, None], [None, None, None], [None, None, None]]



    def __init__(self, name):
        self._action_name = name
        self._as = actionlib.SimpleActionServer(self._action_name, motor_controller.msg.MotorAction,
                                                execute_cb=self.execute_cb, auto_start=False)
        self._as.start()

        for i in self.motors:
            for j in i:
                pub = rospy.Publisher('/zeta_urdf/' + j + '/command', Float64, queue_size=10)
                try:
                    self.publishers[self.motors.index(i)][i.index(j)] = pub
                except IndexError:
                    pass

    def Pos_to_Gazebo(self, pos):
        return pos / 1000

    def findIndex(self, key):
        for c in self.motors:
            for r in c:
                if key in r:
                    return self.motors.index(c), c.index(r)

    def execute_cb(self, goal):
        # helper variables
        r = rospy.Rate(50)
        success = True
        all_moves_done = False
        # publish info to the console for the user
        rospy.loginfo(f'Running action on: {goal.motor_name} with position: {goal.position}')

        # start executing the action
        motor_name = str(goal.motor_name.data).replace('"','')
        x, y = self.findIndex(motor_name)

        self.publishers[x][y].publish(self.Pos_to_Gazebo(goal.position))





        if self._as.is_preempt_requested():
            rospy.loginfo('%s: Preempted' % self._action_name)
            self._as.set_preempted()
            success = False
        self._feedback.success = True

        self._as.publish_feedback(self._feedback)
            # this step is not necessary, the sequence is computed at 1 Hz for demonstration purposes
        r.sleep()

        if self._feedback.success:
            self._result.success = self._feedback.success
            rospy.loginfo('%s: Succeeded' % self._action_name)
            self._as.set_succeeded(self._result)

def callback(data):
    print("HHHHHH")
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

if __name__ == '__main__':
    rospy.init_node('motor_action')
    rospy.Subscriber("/zeta_urdf", Float64, callback)
    # server = MotorAction(rospy.get_name())
    rospy.spin()

"""

# !/usr/bin/env python
import rospy
from std_msgs.msg import Float64


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)


def listener():
    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("/zeta_urdf/FL_1_position_controller/state", Float64, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':
    listener()