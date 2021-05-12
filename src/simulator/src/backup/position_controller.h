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

        void update_desired_state();
        void update_command(void);

    public:
        PositionController();

        void update_current_state(const geometry_msgs::TransformStamped msg);

        geometry_msgs::Twist get_control_command(void);

};
