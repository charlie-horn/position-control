#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TransformStamped.h"

class PositionController
{
    private:
        geometry_msgs::TransformStamped current_state;
        std::vector<float> desired_state;
        geometry_msgs::Twist control_command;
        int count;

        void update_desired_state(){};
        void update_command(void)
        {
            control_command.linear.x = 0; // Desired roll
            control_command.linear.y = 0; // Desired pitch
            control_command.linear.z = 1; // Desired z_dot
            control_command.angular.z = 1; // Desired yaw_dot
        };

    public:
        PositionController()
        {
            count = 0;
        };

        void update_current_state(const geometry_msgs::TransformStamped msg)
        {
            current_state = msg;
            update_desired_state();
            update_command();
        };

        geometry_msgs::Twist get_control_command(void) {
            return control_command;
        };

};
