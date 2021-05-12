;; Auto-generated. Do not edit!


(when (boundp 'simulator::ToggleCam)
  (if (not (find-package "SIMULATOR"))
    (make-package "SIMULATOR"))
  (shadow 'ToggleCam (find-package "SIMULATOR")))
(unless (find-package "SIMULATOR::TOGGLECAM")
  (make-package "SIMULATOR::TOGGLECAM"))
(unless (find-package "SIMULATOR::TOGGLECAMREQUEST")
  (make-package "SIMULATOR::TOGGLECAMREQUEST"))
(unless (find-package "SIMULATOR::TOGGLECAMRESPONSE")
  (make-package "SIMULATOR::TOGGLECAMRESPONSE"))

(in-package "ROS")





(defclass simulator::ToggleCamRequest
  :super ros::object
  :slots ())

(defmethod simulator::ToggleCamRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass simulator::ToggleCamResponse
  :super ros::object
  :slots (_Status ))

(defmethod simulator::ToggleCamResponse
  (:init
   (&key
    ((:Status __Status) "")
    )
   (send-super :init)
   (setq _Status (string __Status))
   self)
  (:Status
   (&optional __Status)
   (if __Status (setq _Status __Status)) _Status)
  (:serialization-length
   ()
   (+
    ;; string _Status
    4 (length _Status)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _Status
       (write-long (length _Status) s) (princ _Status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _Status
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _Status (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass simulator::ToggleCam
  :super ros::object
  :slots ())

(setf (get simulator::ToggleCam :md5sum-) "8fc5f5608d6072d9e82dd30f42a4228c")
(setf (get simulator::ToggleCam :datatype-) "simulator/ToggleCam")
(setf (get simulator::ToggleCam :request) simulator::ToggleCamRequest)
(setf (get simulator::ToggleCam :response) simulator::ToggleCamResponse)

(defmethod simulator::ToggleCamRequest
  (:response () (instance simulator::ToggleCamResponse :init)))

(setf (get simulator::ToggleCamRequest :md5sum-) "8fc5f5608d6072d9e82dd30f42a4228c")
(setf (get simulator::ToggleCamRequest :datatype-) "simulator/ToggleCamRequest")
(setf (get simulator::ToggleCamRequest :definition-)
      "---
string Status

")

(setf (get simulator::ToggleCamResponse :md5sum-) "8fc5f5608d6072d9e82dd30f42a4228c")
(setf (get simulator::ToggleCamResponse :datatype-) "simulator/ToggleCamResponse")
(setf (get simulator::ToggleCamResponse :definition-)
      "---
string Status

")



(provide :simulator/ToggleCam "8fc5f5608d6072d9e82dd30f42a4228c")


