
(cl:in-package :asdf)

(defsystem "freenove_base-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "adc_msg" :depends-on ("_package_adc_msg"))
    (:file "_package_adc_msg" :depends-on ("_package"))
    (:file "buzzer_msg" :depends-on ("_package_buzzer_msg"))
    (:file "_package_buzzer_msg" :depends-on ("_package"))
    (:file "led_msg" :depends-on ("_package_led_msg"))
    (:file "_package_led_msg" :depends-on ("_package"))
    (:file "line_tracking_msg" :depends-on ("_package_line_tracking_msg"))
    (:file "_package_line_tracking_msg" :depends-on ("_package"))
    (:file "motor_msg" :depends-on ("_package_motor_msg"))
    (:file "_package_motor_msg" :depends-on ("_package"))
    (:file "servo_msg" :depends-on ("_package_servo_msg"))
    (:file "_package_servo_msg" :depends-on ("_package"))
  ))