from __future__ import print_function

import sys, time
import serial
import lewansoul_lx16a
from math_libs import *

from time import sleep

SERIAL_PORT = '/dev/ttyUSB0'    # For Linux

ctrl = lewansoul_lx16a.ServoController(
    serial.Serial(SERIAL_PORT, 115200, timeout=1),
)

timez = 1000

def servo_info(id):
    print("Servo id: {}".format(id))
    print("Position: {}".format(ctrl.get_position(id)))
    print("Temperature: {}".format(ctrl.get_temperature(id)))


def convert_values(motor_id, init_val):
    final_val = radToDeg(init_val)
    final_val = degToMotorPos(motor_id, final_val)
    final_val = normalize_inverse(motor_id, final_val)
    return final_val

def conv_ik(id, x, y, z):
    ik = IK_Solver(x, y, z)
    ik_conv = []
    ik_conv.append(convert_values(id, ik[0]))
    ik_conv.append(convert_values(id, ik[1]))
    ik_conv.append(convert_values(id, ik[2]))
    return ik_conv


if __name__ == '__main__':
	ik = IK_Solver(0, 0, 14)
	ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
	ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
	ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
	ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
	ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
	ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
	ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
	ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
	ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

	time.sleep((timez/1000) + 3.05)


	for i in range(3):
		ik = IK_Solver(0, 2, 10)
		ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
		ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
		ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
		ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
		ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
		ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
		ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
		
		ik = IK_Solver(0, 2, 10)
		ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
		ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
		ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

		time.sleep((timez/1000) + 0.05)
		
		
		ik = IK_Solver(0, 4, 15)
		ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
		ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
		ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
		ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
		ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
		ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
		ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
		
		ik = IK_Solver(0, 4, 15)
		ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
		ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
		ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

		time.sleep((timez/1000) + 0.05)
		
		
		
		
		
    
		ik = IK_Solver(0, -4, 14)
		ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
		ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
		ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
		
		ik = IK_Solver(0, 2, 10)
		ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
		ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
		ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
		
		ik = IK_Solver(0, 2, 10)
		ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
		ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
		ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
		ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
		ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

		time.sleep((timez/1000) + 0.05)
		
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
		ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
		ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
		
		ik = IK_Solver(0, 4, 15)
		ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
		ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
		ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
		
		ik = IK_Solver(0, 4, 15)
		ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
		ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
		ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
		
		ik = IK_Solver(0, -4, 14)
		ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
		ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
		ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

		time.sleep((timez/1000) + 0.05)
		
		
	ik = IK_Solver(0, 0, 14)
	ctrl.move(FL1, convert_values(FL1, ik[0]), timez)
	ctrl.move(FL2, convert_values(FL2, ik[1]), timez)
	ctrl.move(FL3, convert_values(FL3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(FR1, convert_values(FR1, ik[0]), timez)
	ctrl.move(FR2, convert_values(FR2, ik[1]), timez)
	ctrl.move(FR3, convert_values(FR3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(BL1, convert_values(BL1, ik[0]), timez)
	ctrl.move(BL2, convert_values(BL2, ik[1]), timez)
	ctrl.move(BL3, convert_values(BL3, ik[2]), timez)
	
	ik = IK_Solver(0, 0, 14)
	ctrl.move(BR1, convert_values(BR1, ik[0]), timez)
	ctrl.move(BR2, convert_values(BR2, ik[1]), timez)
	ctrl.move(BR3, convert_values(BR3, ik[2]), timez)

	time.sleep((timez/1000) + 0.05)
    
    
  
 
