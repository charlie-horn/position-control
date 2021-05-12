#include "geometry_msgs/TransformStamped.h"

class Node
{
    public:
        Node(float x, float y);
        std::string toString();
        //inline bool operator < (Node& lhs, Node& rhs){return lhs.f_cost < rhs.f_cost;};
        Node(int x, int y);
        bool isValid();
        bool isDest(Node*);
        double calculate_H(Node*);
        geometry_msgs::TransformStamped toMsg();
        int y;
        int x;
        Node* parent;
        //int num_coords = 100;
        float g_cost;
        float h_cost;
        float f_cost;
};
