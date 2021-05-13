#include "geometry_msgs/TransformStamped.h"


std::vector<geometry_msgs::TransformStamped> get_landmarks() 
{
    std::vector<geometry_msgs::TransformStamped> landmarks(5);
    
    landmarks[0].transform.translation.x = 1.0;
    landmarks[0].transform.translation.y = 1.0;
    landmarks[0].transform.translation.z = 3;

    landmarks[1].transform.translation.x = 7.149;
    landmarks[1].transform.translation.y = 5.829;
    landmarks[1].transform.translation.z = 3;

    landmarks[2].transform.translation.x = 8.751;
    landmarks[2].transform.translation.y = 4.740;
    landmarks[2].transform.translation.z = 3;

    landmarks[3].transform.translation.x = 3.219;
    landmarks[3].transform.translation.y = 1.403;
    landmarks[3].transform.translation.z = 3;

    landmarks[4].transform.translation.x = 1.933;
    landmarks[4].transform.translation.y = 6.608;
    landmarks[4].transform.translation.z = 3;


    
    return landmarks;
};
