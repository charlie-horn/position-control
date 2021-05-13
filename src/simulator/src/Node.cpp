
#include "Node.h"
#include "Obstacles.h"
#include "ros/console.h"
Node::Node(float msg_x, float msg_y)
{
    x = static_cast<int>(msg_x);
    y = static_cast<int>(msg_y);
};

Node::Node(int msg_x, int msg_y)
{
    x = msg_x;
    y = msg_y;
};

std::string Node::toString()
{
    std::string s = "\n----------\nNode: \n\tID: ("
           + std::to_string(x) + "," + std::to_string(y) +
           ")\n\tCost: \n\t\tG: " + std::to_string(g_cost) +
           "\n\t\tH:" + std::to_string(h_cost) +
           "\n\t\tF:" + std::to_string(f_cost) +
           //"\n\tParent:(" + std::to_string(parent->x) + ","+std::to_string(parent->y)+")"+
           "\n----------";
          
    return s;
}
bool Node::isValid()
{
    std::vector<std::vector<float>> obstacles = get_obstacles();
    for (int i=0; i<obstacles.size(); ++i) {
        int x_coord = obstacles[i][0]*10;
        int y_coord = obstacles[i][1]*10;
        int x_dist = std::abs(x - x_coord);
        int y_dist = std::abs(y - y_coord);
        float dist = sqrt(pow(x_dist,2)+pow(y_dist,2));
        if (dist < obstacles[i][2]*10+10){
            return false;
        }
    }
    if (x>100 || y>100 || x<0 || y<0){
        return false;
    }
    return true;
}

bool Node::isDest(Node* dest)
{
    if (x==dest->x && y==dest->y){
        return true;
    }
    return false;
}

double Node::calculate_H(Node* dest)
{
    float H = sqrt(pow(x-dest->x,2)+pow(y-dest->y,2));
    return H;
}

geometry_msgs::TransformStamped Node::toMsg(){
    geometry_msgs::TransformStamped msg;
    msg.transform.translation.x = static_cast<float>(x)/static_cast<float>(10);
    msg.transform.translation.y = static_cast<float>(y)/static_cast<float>(10);
    msg.transform.translation.z = 3.0;
    ROS_DEBUG_STREAM_NAMED("path_creation","Returning msg");
    return msg;
}

