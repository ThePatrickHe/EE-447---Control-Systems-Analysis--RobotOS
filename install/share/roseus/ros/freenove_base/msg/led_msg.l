;; Auto-generated. Do not edit!


(when (boundp 'freenove_base::led_msg)
  (if (not (find-package "FREENOVE_BASE"))
    (make-package "FREENOVE_BASE"))
  (shadow 'led_msg (find-package "FREENOVE_BASE")))
(unless (find-package "FREENOVE_BASE::LED_MSG")
  (make-package "FREENOVE_BASE::LED_MSG"))

(in-package "ROS")
;;//! \htmlinclude led_msg.msg.html


(defclass freenove_base::led_msg
  :super ros::object
  :slots (_occupied_channel _r _g _b ))

(defmethod freenove_base::led_msg
  (:init
   (&key
    ((:occupied_channel __occupied_channel) 0)
    ((:r __r) 0)
    ((:g __g) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _occupied_channel (round __occupied_channel))
   (setq _r (round __r))
   (setq _g (round __g))
   (setq _b (round __b))
   self)
  (:occupied_channel
   (&optional __occupied_channel)
   (if __occupied_channel (setq _occupied_channel __occupied_channel)) _occupied_channel)
  (:r
   (&optional __r)
   (if __r (setq _r __r)) _r)
  (:g
   (&optional __g)
   (if __g (setq _g __g)) _g)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; int32 _occupied_channel
    4
    ;; int32 _r
    4
    ;; int32 _g
    4
    ;; int32 _b
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _occupied_channel
       (write-long _occupied_channel s)
     ;; int32 _r
       (write-long _r s)
     ;; int32 _g
       (write-long _g s)
     ;; int32 _b
       (write-long _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _occupied_channel
     (setq _occupied_channel (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _r
     (setq _r (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _g
     (setq _g (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get freenove_base::led_msg :md5sum-) "0d557764c30ab24fea6db8ccf3b5bbbd")
(setf (get freenove_base::led_msg :datatype-) "freenove_base/led_msg")
(setf (get freenove_base::led_msg :definition-)
      "int32 occupied_channel
int32 r
int32 g
int32 b
")



(provide :freenove_base/led_msg "0d557764c30ab24fea6db8ccf3b5bbbd")


