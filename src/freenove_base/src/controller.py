#!/usr/bin/env python
from turtle import update
import rospy
import cv2
import time
import numpy as np
from freenove_base.srv import ultrasonic_srv
from freenove_base.msg import motor_msg,servo_msg,line_tracking_msg

#Import the classes to use in main
from ultrasonic_run import run_ever
from line_tracking import Line_Tracking
from opencv import color_detection

class Controller:
    def __init__(self,motor_topic,line_tracking_topic):
        # Publisher
        self.motor_pub = rospy.Publisher(motor_topic, motor_msg, queue_size=3)

if __name__ == '__main__':
    rospy.init_node('controller', anonymous=True)
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

    run_line = Line_Tracking(motor_topic,line_tracking_topic)
    message = run_ever(TOPIC)
    while not rospy.is_shutdown(): 
        rospy.on_shutdown(message.end)
        distance = message.get_distance()
        print(distance)
        time.sleep(.1)

        #Path 1:
        if distance < 16:
            run_line.check = 0
            run_line.update([0,0,0,0])
            break
        else:
            run_line.check = 1
        
        #Turn around:
        open

    # #Path 1:
    # while distance > 10:
    #     run_line = Line_Tracking(motor_topic,line_tracking_topic)

    # #distance sensor
    # message = run_ever(TOPIC)
    # while not rospy.is_shutdown(): 
    #     distance = message.get_distance()
    #     print(distance)
    #     time.sleep(.2)
    print("\nexit interface")