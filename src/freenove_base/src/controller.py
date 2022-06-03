#!/usr/bin/env python
import rospy
import cv2
import numpy as np
from freenove_base.srv import ultrasonic_srv
from freenove_base.msg import motor_msg,servo_msg,line_tracking_msg
from ultrasonic_run import run_ever
from line_tracking import Line_Tracking
from opencv import color_detection


# class control:
#     def __init__(self,TOPIC):
#         self.TOPIC =

if __name__ == '__main__':
    rospy.init_node('final_lab', anonymous=True)
    #topics
    motor_topic = '/car/hardware/motor'
    line_tracking_topic = '/car/hardware/line_tracking'
    
    # create a topic dictionary
    # If there has a launch file for this file, rospy.get_param will load parameter from launch instead default
    TOPIC ={}
    TOPIC["motor_topic"] = rospy.get_param("~motor_topic",'/car/hardware/motor')
    TOPIC["servo_topic"] = rospy.get_param("~servo_topic",'/car/hardware/servo')
    TOPIC["buzzer_topic"] = rospy.get_param("~buzzer_topic",'/car/hardware/buzzer')
    TOPIC["led_topic"] = rospy.get_param("~led_topic",'/car/hardware/led')
    TOPIC["line_tracking_topic"] = rospy.get_param("~line_tracking_topic",'/car/hardware/line_tracking')
    TOPIC["adc_topic"] = rospy.get_param("~adc_topic",'/car/hardware/adc')
    TOPIC["ultrasonic_topic"] = rospy.get_param("~ultrasonic_topic",'/car/hardware/ultrasonic')

    message = run_ever(TOPIC)
    import time
    while not rospy.is_shutdown(): 
        distance = message.get_distance()
        print(distance)
        time.sleep(.1)
    print("\nexit interface")