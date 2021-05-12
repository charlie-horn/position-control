#include "geometry_msgs/TransformStamped.h"
#include "Node.h"

class PathPlanner
{
    private:
        int num_coords = 100;
        std::vector<geometry_msgs::TransformStamped> get_segment(geometry_msgs::TransformStamped start,geometry_msgs::TransformStamped end);
        std::vector<Node*> a_star(Node* start, Node* end);
        std::vector<Node*> make_path(Node*);
    public:
        PathPlanner(std::vector<int> visits);
        std::vector<std::vector<Node*>> map;//{std::vector<std<vector<Node*>>(100, std::vector<Node*>(100, new Node))};
        std::vector<std::vector<bool>> closed_list;//{std::vector<std::vector<bool>>(100, std::vector<bool>(100, false))};
        std::vector<std::vector<geometry_msgs::TransformStamped>> path;
        PathPlanner(int length = 4);


};
