#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include "PathPlanner.h"
#include "PositionController.h"
#include "ros/console.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/TransformStamped.h"
//#include "PositionController.cpp"
//#include "position_controller.h"
//#include "interface.h"

float z;

void update_z(const geometry_msgs::TransformStamped msg)
{
    z = msg.transform.translation.z;
    ROS_DEBUG_STREAM_NAMED("command_delay","Updating..." << z);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "position_control");

    //ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,ros::console::levels::Debug);
    ros::console::set_logger_level("ros.simulator.path_following",ros::console::levels::Debug);
    ros::console::notifyLoggerLevelsChanged();
    //ROS_DEBUG("DEBUG");
    //ROS_INFO("INFO");
    //ROS_WARN("WARN");
    //std::cout << "HELLO" << std::endl;
    //ROS_ERROR("ERROR");
    ros::NodeHandle n;

    ros::Publisher cmd_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_RHC", 32);
    ros::Publisher des_pub = n.advertise<geometry_msgs::TransformStamped>("/des_pos", 32);
    
    ros::Publisher takeoff = n.advertise<std_msgs::Empty>("/ardrone/takeoff",1);
    std_msgs::Empty takeoff_msg;
    
    ros::Subscriber takeoff_sub = n.subscribe("/vicon/ARDroneCarre/ARDroneCarre",32, update_z);

    while(z==0.0){
        //takeoff.publish(takeoff_msg);
        ROS_DEBUG_STREAM_NAMED("command_delay","Waiting..." << z);
        ros::spinOnce();
        continue;
    }


    std::vector<int> visits = {4,3,2};
    //while(ros::ok()){ros::spinOnce();}
    PathPlanner planner(visits);

    PositionController controller(planner.path);

    ros::Subscriber sub = n.subscribe("/vicon/ARDroneCarre/ARDroneCarre",32, &PositionController::update_current_state, &controller);

    //std::vector<float> current_state(6);
    
    //std::vector<float> desired_state(6);

    geometry_msgs::Twist control_command;

    ros::Rate rate(200);

    while(ros::ok())
    {
        //desired_state = generator.get_desired_state(current_state);
        control_command = controller.get_control_command();

        cmd_pub.publish(control_command);
        des_pub.publish(controller.desired_state);
        ros::spinOnce();

        rate.sleep();
    }
}
