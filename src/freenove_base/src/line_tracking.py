#!/usr/bin/env python
import rospy
from freenove_base.msg import motor_msg,line_tracking_msg

LMR = 0x00

class Line_Tracking:
    def __init__(self,motor_topic,line_tracking_topic):
        # Publisher
        self.motor_pub = rospy.Publisher(motor_topic, motor_msg, queue_size=3)
        # Subscriber
        self.line_tracking_sub = rospy.Subscriber(line_tracking_topic,line_tracking_msg,
                            self.line_tracking_callback, queue_size=3)
       
        #ADDED THIS CHECK VARIABLE TO STOP LINE TRACKING IN CONTROLLER
        self.check = 1

    def line_tracking_callback(self,msg): 
        flag=1
        self.LMR=0x00
        # Get left,mid,right sensors statement
        if msg.left==True:
            self.LMR=(self.LMR | 4)
        if msg.mid==True:
            self.LMR=(self.LMR | 2)
        if msg.right==True:
            self.LMR=(self.LMR | 1)

        # Motors' speed and direction judgment
        if self.LMR==2:
            wheels_pose =[600,600,600,600]
        elif self.LMR==4:
            wheels_pose =[-1000,-1000,1500,1500]
        elif self.LMR==6:
            wheels_pose =[-1000,-1000,3000,3000]
        elif self.LMR==1:
            wheels_pose =[1500,1500,-1000,-1000]
        elif self.LMR==3:
            wheels_pose =[3000,3000,-1000,-1000]            
        elif self.LMR==7: 
            wheels_pose =[0,0,0,0]
        else:
            flag=0 

        # stock values
        # if self.LMR==2:
        #     wheels_pose =[800,800,800,800]
        # elif self.LMR==4:
        #     wheels_pose =[-1500,-1500,2500,2500]
        # elif self.LMR==6:
        #     wheels_pose =[-2000,-2000,4000,4000]
        # elif self.LMR==1:
        #     wheels_pose =[2500,2500,-1500,-1500]
        # elif self.LMR==3:
        #     wheels_pose =[4000,4000,-2000,-2000]            
        # elif self.LMR==7: 
        #     wheels_pose =[0,0,0,0]
        
        # Publish only if judgment is changed           
        if flag == 1 and self.check == 1:
            self.update(wheels_pose)
        
    def update(self,wheels_pose):
        move = motor_msg()
        move.left_Upper_Wheel = wheels_pose[0]
        move.left_Lower_Wheel = wheels_pose[1]
        move.right_Upper_Wheel = wheels_pose[2]
        move.right_Lower_Wheel = wheels_pose[3]
        self.motor_pub.publish(move)
        

if __name__ == '__main__':
    rospy.init_node('line_follower', anonymous=True)
    motor_topic = '/car/hardware/motor'
    line_tracking_topic = '/car/hardware/line_tracking'

    run_line = Line_Tracking(motor_topic,line_tracking_topic)
    # Keep running node run 
    rospy.spin()
    print("exit tracking")
