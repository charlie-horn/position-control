#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TransformStamped.h"
#include "position_controller.h"

void PositionController::update_command(void)
{
    control_command.linear.x = 0; // Desired roll
    control_command.linear.y = 0; // Desired pitch
    control_command.linear.z = 1; // Desired z_dot
    control_command.angular.z = 1; // Desired yaw_dot
};


PositionController::PositionController()
{
    int count = 0;
    //geometry_msgs::Twist control_command;

};

void PositionController::update_current_state(geometry_msgs::TransformStamped msg)
{
    current_state = msg;
    update_desired_state();
    update_command();
};

geometry_msgs::Twist PositionController::get_control_command() {
    return control_command;
};
