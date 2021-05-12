
(cl:in-package :asdf)

(defsystem "simulator-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ToggleCam" :depends-on ("_package_ToggleCam"))
    (:file "_package_ToggleCam" :depends-on ("_package"))
  ))