;; Auto-generated. Do not edit!


(when (boundp 'vicon::MotorCommands)
  (if (not (find-package "VICON"))
    (make-package "VICON"))
  (shadow 'MotorCommands (find-package "VICON")))
(unless (find-package "VICON::MOTORCOMMANDS")
  (make-package "VICON::MOTORCOMMANDS"))

(in-package "ROS")
;;//! \htmlinclude MotorCommands.msg.html


(defclass vicon::MotorCommands
  :super ros::object
  :slots (_motor_cmd ))

(defmethod vicon::MotorCommands
  (:init
   (&key
    ((:motor_cmd __motor_cmd) (make-array 4 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _motor_cmd __motor_cmd)
   self)
  (:motor_cmd
   (&optional __motor_cmd)
   (if __motor_cmd (setq _motor_cmd __motor_cmd)) _motor_cmd)
  (:serialization-length
   ()
   (+
    ;; float64[4] _motor_cmd
    (* 8    4)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[4] _motor_cmd
     (dotimes (i 4)
       (sys::poke (elt _motor_cmd i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[4] _motor_cmd
   (dotimes (i (length _motor_cmd))
     (setf (elt _motor_cmd i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get vicon::MotorCommands :md5sum-) "424a0da2970783751aa94563cd70d0bb")
(setf (get vicon::MotorCommands :datatype-) "vicon/MotorCommands")
(setf (get vicon::MotorCommands :definition-)
      "# MotorCommands
#
# Rikky Duivenvoorden 2017-01-30 -- For use in AER1217 Winter 2017
#
# Data communicates the motor commands in RPM as a four element array in the
# following order [front_left, front_right, rear_left, rear_right]

float64[4] motor_cmd

")



(provide :vicon/MotorCommands "424a0da2970783751aa94563cd70d0bb")

