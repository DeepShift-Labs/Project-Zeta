#! /usr/bin/env python3

import rospy
import actionlib
import motor_controller.msg



class MotorAction(object):
    # create messages that are used to publish feedback/result
    _feedback = motor_controller.msg.MotorFeedback()
    _result = motor_controller.msg.MotorResult()

    def __init__(self, name):
        self._action_name = name
        self._as = actionlib.SimpleActionServer(self._action_name, motor_controller.msg.MotorAction,
                                                execute_cb=self.execute_cb, auto_start=False)
        self._as.start()

    def execute_cb(self, goal):
        # helper variables
        r = rospy.Rate(1)
        success = True

        # append the seeds for the fibonacci sequence
        self._feedback.success = True


        # publish info to the console for the user
        rospy.loginfo(f'running action on: {goal.motor_name}')

        # start executing the action
        # for i in range(1, goal.order):
        #     # check that preempt has not been requested by the client
        #     if self._as.is_preempt_requested():
        #         rospy.loginfo('%s: Preempted' % self._action_name)
        #         self._as.set_preempted()
        #         success = False
        #         break
        #     self._feedback.sequence.append(self._feedback.sequence[i] + self._feedback.sequence[i - 1])
            # publish the feedback
        self._as.publish_feedback(self._feedback)
            # this step is not necessary, the sequence is computed at 1 Hz for demonstration purposes
        r.sleep()

        if self._feedback.success:
            self._result.success = self._feedback.success
            rospy.loginfo('%s: Succeeded' % self._action_name)
            self._as.set_succeeded(self._result)


if __name__ == '__main__':
    rospy.init_node('motor_action')
    server = MotorAction(rospy.get_name())
    rospy.spin()