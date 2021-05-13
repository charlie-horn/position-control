#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TransformStamped.h"
#include "PositionController.h"
#include <Eigen>

void PositionController::update_command(void)
{
    float x_double_dot_des = x_double_dot_P_gain*(desired_state.transform.translation.x -
    current_state.transform.translation.x); // TODO add derivative term
    float y_double_dot_des = y_double_dot_P_gain*(desired_state.transform.translation.y -
    current_state.transform.translation.y); //TODO add derivative term

    
    Eigen::Quaternionf q_curr(current_state.transform.rotation.x,
                              current_state.transform.rotation.y,
                              current_state.transform.rotation.z,
                              current_state.transform.rotation.w);
    auto euler_curr = q_curr.toRotationMatrix().eulerAngles(0,1,2);
    float roll_curr = euler_curr[0];
    float pitch_curr = euler_curr[1];
    float yaw_curr = euler_curr[2];
    
    Eigen::Quaternionf q_des(desired_state.transform.rotation.x,
                             desired_state.transform.rotation.y,
                             desired_state.transform.rotation.z,
                             desired_state.transform.rotation.w);
    auto euler_des = q_des.toRotationMatrix().eulerAngles(0,1,2);
    //float roll_des = euler_des[0];
    //float pitch_des = euler_des[1];
    float yaw_des = euler_des[2];

    float thrust = (z_double_dot + 9.8)/(cos(roll_curr)*cos(pitch_curr));
    
    float roll_des = std::asin(std::max(std::min(-y_double_dot_des/thrust,1.0f),-1.0f));
    float pitch_des = std::asin(std::max(std::min(x_double_dot_des/(thrust*cos(roll_des)),1.0),-1.0));
    
    float roll_des_base = std::max(std::min(roll_des*cos(yaw_curr)+pitch_des*sin(yaw_curr),1.0),-1.0);
    float pitch_des_base = std::max(std::min(-roll_des*sin(yaw_curr)+pitch_des*cos(yaw_curr),1.0),-1.0);

    float z_dot_des = z_dot_P_gain*(desired_state.transform.translation.z - current_state.transform.translation.z);
    float yaw_error = yaw_des - yaw_curr;
    if (yaw_error > 3.14) { yaw_error = yaw_error - 6.28;}
    else if (yaw_error < -3.14) { yaw_error = yaw_error + 6.28;};
    float yaw_dot_des = yaw_dot_P_gain*yaw_error;

    control_command.linear.x = roll_des_base; // Desired roll
    control_command.linear.y = pitch_des_base; // Desired pitch
    control_command.linear.z = z_dot_des; // Desired z_dot
    control_command.angular.z = yaw_dot_des; // Desired yaw_dot
};


PositionController::PositionController(std::vector<std::vector<geometry_msgs::TransformStamped>> p)
{
    path = p;
    segment_count = 0;
    position_count = 0;
    dir = 1;
    threshold = 0.001;
    desired_state = path[segment_count][position_count];
    update_command();

};

void PositionController::update_current_state(geometry_msgs::TransformStamped msg)
{
    previous_state = current_state;
    current_state = msg;

    dt = (current_state.header.stamp - previous_state.header.stamp).toSec();

    previous_z_dot = z_dot;
    z_dot = (current_state.transform.translation.z - current_state.transform.translation.z)/dt;
    z_double_dot = (z_dot - previous_z_dot)/dt;
    
    update_desired_state();
    
    x_double_dot_P_gain = 0.05; 
    x_double_dot_D_gain = 1.4;

    y_double_dot_P_gain = x_double_dot_P_gain;
    y_double_dot_D_gain = x_double_dot_D_gain;

    yaw_dot_P_gain = 0.5;
    z_dot_P_gain = 0.15;

    update_command();
};

void PositionController::update_desired_state()
{   
    // Change direction if necessary
    if (position_count + dir > path[segment_count].size()-1 || position_count + dir < 0) {
        if (segment_count + dir < 0 || segment_count + dir > path.size() - 1){
            dir = -1*dir;
        }
    }

    // Update desired state
    if (get_dist() < threshold) {
        if (position_count == path[segment_count].size()-1 && dir == 1){
            position_count = 0;
            ++segment_count;
        } else if (position_count == 0 && dir == -1){
            --segment_count;
            position_count = path[segment_count].size()-1;
        } else {
            position_count = position_count + dir;
        }
    }
    //ROS_DEBUG_STREAM_NAMED("path_following","PATH at curr: " << path[segment_count][position_count]);
    //ROS_DEBUG_STREAM_NAMED("path_following","PATH at 0: " << path[0][0]);
    desired_state = path[segment_count][position_count];
}

float PositionController::get_dist() {
    float x_dist = abs(current_state.transform.translation.x - desired_state.transform.translation.x);
    float y_dist = abs(current_state.transform.translation.y - desired_state.transform.translation.y);
    float z_dist = abs(current_state.transform.translation.z - desired_state.transform.translation.z);
    float dist = x_dist + y_dist + z_dist;

    return dist;
}

