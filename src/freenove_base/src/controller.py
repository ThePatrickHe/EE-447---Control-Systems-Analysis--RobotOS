#!/usr/bin/env python
import rospy
import cv2
import time
import numpy as np
from freenove_base.srv import ultrasonic_srv
from freenove_base.msg import motor_msg,servo_msg,line_tracking_msg

#Import the classes to use in main
from ultrasonic_run import * #run_ever
from line_tracking import * #Line_Tracking
from opencv import * #color_detection

distance = 1000

# class controller:
#     def __init__(self,TOPIC):
#         self.TOPIC = TOPIC
#         # Publisher
#         # self.motor_pub = rospy.Publisher(motor_topic, motor_msg, queue_size=3)

#     def path1(motor_topic,line_tracking_topic):
#         #Path 1:
#         run_line.check = 1
#         if distance < 16:
#             run_line.check = 0
#             run_line.update([0,0,0,0])
#             #Turn around:
#             run_line.update([-500,-500,500,500])
#             time.sleep(2)        

#     def end():
#         run_line = Line_Tracking(motor_topic,line_tracking_topic)
#         run_line.update([0,0,0,0])

if __name__ == '__main__':
    rospy.init_node('controller', anonymous=True)

    motor_topic = '/car/hardware/motor'
    line_tracking_topic = '/car/hardware/line_tracking'
    ultrasonic_topic = 'car/hardware/ultrasonic'

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

    # control = controller(TOPIC)
    # message = run_ever(TOPIC)
    # run_line = Line_Tracking(motor_topic,line_tracking_topic)
    # run_line.check = 1
    # # control.path1(motor_topic,line_tracking_topic)
    # while not rospy.is_shutdown(): 
    #     # rospy.on_shutdown(control.end)
    #     distance = run_ever.get_distance(message)
    #     print(distance)


    # while not rospy.is_shutdown(): 
    # rospy.on_shutdown(message.end)
    
    run_line = Line_Tracking(motor_topic,line_tracking_topic)
    message = run_ever(TOPIC)
    
    ###########################
    distance_values = [30,30,30,30,30]
    ###################

    #Path 1:
    run_line.check = 1
    while run_line.check == 1:
        distance = message.get_distance()
        # print(distance)
        distance_values.append(distance)
        # time.sleep(.1)

        #################
        #take the last 5 values
        # find an average
        # compare to that average
        ##########################################

        average = 0
        for i in range(len(distance_values) - 5, len(distance_values), 1):
            average += distance_values[i]

        average = average/5

        ##########################################

        if average < 16:
            run_line.check = 0
            run_line.update([0,0,0,0])

    # Turn around:

    run_line.update([-1500,-1500,1500,1500])
    time.sleep(1.4)
    run_line.update([0,0,0,0])

    #OpenCV
    display_image = 1
    run = color_detection(TOPIC,display_image)
    while run_line.LMR == 0:
        run.loop()
        if cv2.waitKey(10) & 0xFF == ord('q'):
            break
    run.cap.release()
    cv2.destroyWindow('block_detect')

    #stop all movement at second line
    run_line.update([0,0,0,0])
    #re-enable
    run_line.check = 1
    while run_line.LMR != 7:
        run_line.check = 1
    run_line.check = 0
   
    #stop everything
    run_line.update([0,0,0,0])
    print("\nexit interface")