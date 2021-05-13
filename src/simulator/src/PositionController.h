#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TransformStamped.h"

class PositionController
{
    private:
        std::vector<std::vector<geometry_msgs::TransformStamped>> path;

        geometry_msgs::TransformStamped previous_state;
        geometry_msgs::TransformStamped current_state;

        float threshold;

        float dt;
        float previous_z_dot;
        float z_dot;
        float z_double_dot;

        geometry_msgs::Twist control_command;
        int position_count;
        int segment_count;
        int dir;

        float x_double_dot_P_gain; 
        float x_double_dot_D_gain; 

        float y_double_dot_P_gain;
        float y_double_dot_D_gain;

        float yaw_dot_P_gain;
        float z_dot_P_gain;

        void update_desired_state();
        void update_command(void);
        float get_dist(void);

    public:
        PositionController(std::vector<std::vector<geometry_msgs::TransformStamped>> p);
        geometry_msgs::TransformStamped desired_state;
        void update_current_state(const geometry_msgs::TransformStamped msg);

        geometry_msgs::Twist get_control_command(void){return control_command;};
};
