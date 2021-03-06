#include "geometry_msgs/TransformStamped.h"
#include "PathPlanner.h"
#include "Landmarks.h"
#include "Obstacles.h"
#include "ros/console.h"
#include "matplotlibcpp.h"
//#include "Node.h"
namespace plt = matplotlibcpp;

std::vector<Node*> PathPlanner::make_path(Node* dest)
{
    Node* node = dest;
    std::vector<Node*> nodes;
    std::vector<int> plot_x;
    std::vector<int> plot_y;

    ROS_DEBUG_STREAM_NAMED("conversion","Tracing back path");
    while (node->parent->x != node->x || node->parent->y != node->y) {
//        ROS_DEBUG_STREAM_NAMED("conversion", "Adding node: " << node->toString() << " with parent " <<
//        node->parent->toString());
        nodes.push_back(node);
        plot_x.push_back(node->x);
        plot_y.push_back(node->y);
        node = node->parent;
    }


    // Plot Results
    // Plot Landmarks
    std::vector<geometry_msgs::TransformStamped> landmarks = get_landmarks();
    std::vector<float> landmarks_x;
    std::vector<float> landmarks_y;
    for (int i=0; i<landmarks.size(); ++i){
        landmarks_x.push_back(10*landmarks[i].transform.translation.x);
        landmarks_y.push_back(10*landmarks[i].transform.translation.y);
    }
    // Plot Obstacles
    std::vector<std::vector<float>> obstacles = get_obstacles();
    
    std::vector<float> plot_obstacles_x_1;
    std::vector<float> plot_obstacles_y_1;
    
    std::vector<float> plot_obstacles_x_2;
    std::vector<float> plot_obstacles_y_2;

    std::vector<float> plot_obstacles_x_3;
    std::vector<float> plot_obstacles_y_3;

    std::vector<float> plot_obstacles_x_4;
    std::vector<float> plot_obstacles_y_4;

    std::vector<float> plot_obstacles_x_5;
    std::vector<float> plot_obstacles_y_5;

    std::vector<float> plot_obstacles_x_6;
    std::vector<float> plot_obstacles_y_6;

    int num_points = 20;
    for (int i=0; i<=20; ++i){
        plot_obstacles_x_1.push_back(10*(obstacles[0][0]+obstacles[0][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_1.push_back(10*(obstacles[0][1]+obstacles[0][2]*sin(i*6.3/num_points)));
        plot_obstacles_x_2.push_back(10*(obstacles[1][0]+obstacles[1][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_2.push_back(10*(obstacles[1][1]+obstacles[1][2]*sin(i*6.3/num_points)));
        plot_obstacles_x_3.push_back(10*(obstacles[2][0]+obstacles[2][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_3.push_back(10*(obstacles[2][1]+obstacles[2][2]*sin(i*6.3/num_points)));
        plot_obstacles_x_4.push_back(10*(obstacles[3][0]+obstacles[3][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_4.push_back(10*(obstacles[3][1]+obstacles[3][2]*sin(i*6.3/num_points)));
        plot_obstacles_x_5.push_back(10*(obstacles[4][0]+obstacles[4][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_5.push_back(10*(obstacles[4][1]+obstacles[4][2]*sin(i*6.3/num_points)));
        plot_obstacles_x_6.push_back(10*(obstacles[5][0]+obstacles[5][2]*cos(i*6.3/num_points)));
        plot_obstacles_y_6.push_back(10*(obstacles[5][1]+obstacles[5][2]*sin(i*6.3/num_points)));
    }

    plt::plot(plot_x,plot_y,"-g",plot_obstacles_x_1,plot_obstacles_y_1,"-r",plot_obstacles_x_2,plot_obstacles_y_2,"-r",plot_obstacles_x_3,plot_obstacles_y_3,"-r",plot_obstacles_x_4,plot_obstacles_y_4,"-r",plot_obstacles_x_5,plot_obstacles_y_5,"-r",plot_obstacles_x_6,plot_obstacles_y_6,"-r",landmarks_x, landmarks_y, "ob");
    plt::show();
    ROS_DEBUG_STREAM_NAMED("conversion","Done tracing");
    nodes.push_back(node);
    std::reverse(nodes.begin(), nodes.end());
    return nodes;
}

std::vector<Node*> PathPlanner::a_star(Node* start, Node* end)
{
    std::vector<std::vector<Node*>> map(num_coords, std::vector<Node*>(num_coords, new Node(0,0)));
    //Node* map[num_coords][num_coords];
    //std::vector<std::vector<bool>(num_coords)>(num_coords) 
    bool closed_list[num_coords][num_coords];
    ROS_DEBUG_STREAM_NAMED("segment_planner","---- Starting A*");
    std::vector<Node*> open_list;
    std::vector<Node*> empty;

    // initialize map
    ROS_DEBUG_STREAM_NAMED("segment_planner","---- Initializing map");
    for (int i=0; i<num_coords; ++i){

        for (int j=0; j<num_coords; ++j) {
           //ROS_DEBUG_STREAM_NAMED("segment_planner","---- "<<i<<" "<<j);
            map[i][j] = new Node(i,j);
            map[i][j]->f_cost = FLT_MAX;
            map[i][j]->g_cost = FLT_MAX;
            map[i][j]->h_cost = FLT_MAX;
            //ROS_DEBUG_STREAM_NAMED("segment_planner","---");
            map[i][j]->parent = nullptr;
            //map[i][j]->x = i;
            //map[i][j]->y = j;
            closed_list[i][j] = false;
        }
    }
    ROS_DEBUG_STREAM_NAMED("segment_planner","Before initializing start:"<<map[1][1]->toString());
    ROS_DEBUG_STREAM_NAMED("segment_planner","Initializing start point: "<<start->toString());
    // Initialize starting point
    map[start->x][start->y]->f_cost = 0.0;
    map[start->x][start->y]->g_cost = 0.0;
    map[start->x][start->y]->h_cost = 0.0;
    map[start->x][start->y]->parent = map[start->x][start->y];
    ROS_DEBUG_STREAM_NAMED("conversion","Done Initializing start point: "<<map[start->x][start->y]->toString());

    ROS_DEBUG_STREAM_NAMED("segment_planner","After initializing start:"<<map[1][1]->toString());
    
    open_list.push_back(map[start->x][start->y]);

    bool destinationFound = false;
    
    while (!open_list.empty() && open_list.size()<num_coords*num_coords) {
        
        // Find and remove neighbouring undiscovered nodes with lowest f score
        Node* node;
        ROS_DEBUG_STREAM_NAMED("segment_planner","---- Looping finding lowest F score");
        do {
            float lowest_f = FLT_MAX;
            int lowest_id = -1;
            for (int i=0; i<open_list.size(); ++i){
                //ROS_DEBUG_STREAM_NAMED("segment_planner","---- "<<i);
                Node* curr_node = open_list[i];
                if (curr_node->f_cost < lowest_f) {
                    lowest_f = curr_node->f_cost;
                    lowest_id = i;
                    node = curr_node;
                }
            }
            open_list.erase(open_list.begin()+lowest_id);
        } while(node->isValid() == false);
        ROS_DEBUG_STREAM_NAMED("conversion","Popped: " << node->toString());

        closed_list[node->x][node->y] = true;

        for (int newX = -1; newX <= 1; ++newX) {
            for (int newY = -1; newY <= 1; ++newY) {
                double gNew, hNew, fNew;
                if(node->x+newX<0 || node->y+newY<0){continue;}
                Node* new_node = map[node->x + newX][node->y + newY];
                //new_node->x = node->x + newX;
                //new_node->y = node->y + newY;

                if (new_node->isValid()) {
                    if (new_node->isDest(end))
                    {
                        //Destination found - make path
                        new_node->parent = node;
                        ROS_DEBUG_STREAM_NAMED("conversion","DESTINATION FOUND"<<new_node->toString() <<
                        new_node->parent->toString());
                        destinationFound = true;
                        return make_path(new_node);
                    }
                    else if (closed_list[new_node->x][new_node->y] == false)
                    {
                        gNew = node->g_cost + 1.0;
                        ROS_DEBUG_STREAM_NAMED("h_cost",node->toString());
                        hNew = new_node->calculate_H(end);
                        ROS_DEBUG_STREAM_NAMED("h_cost","\nH_COST: ("<< new_node->x << "," << new_node->y+") " << hNew);
                        fNew = gNew + hNew;
                        // ROS_DEBUG_STREAM_NAMED("segment_planner","---- Neighbour node is valid ("<<new_node->x<<","<<new_node->y<<"):"<<fNew<<" vs "<<map[new_node->x][new_node->y]->f_cost);
                        // Check if this path is better than the one already present
                        if (map[new_node->x][new_node->y]->f_cost > fNew)
                        {
                            // Update the details of this neighbour node
                            map[new_node->x][new_node->y]->f_cost = fNew;
                            map[new_node->x][new_node->y]->g_cost = gNew;
                            map[new_node->x][new_node->y]->h_cost = hNew;
                            map[new_node->x][new_node->y]->parent = node;
                            //ROS_DEBUG_STREAM_NAMED("conversion","---- Adding node"
                            //<<new_node->x<<","<<new_node->y<<" to open list with parent:  "<< node->toString());
                            open_list.emplace_back(map[new_node->x][new_node->y]);
                        }
                    }
                }
            }
        }
    }
    if (destinationFound == false) {
        std::cout << "Destination not found" << std::endl;
        return empty;
    }
}

Node* msg_to_node(geometry_msgs::TransformStamped msg) {
    //Node node(msg.transform.translation.x*10, msg.transform.translation.y*10);
    float x = msg.transform.translation.x*10;
    float y = msg.transform.translation.y*10;
    Node* node = new Node(x, y);
    return node;
}

std::vector<geometry_msgs::TransformStamped> PathPlanner::get_segment(geometry_msgs::TransformStamped start,
                                                         geometry_msgs::TransformStamped end) {
    Node* start_node = msg_to_node(start);
    Node* end_node = msg_to_node(end);
    std::vector<Node*> nodes = a_star(start_node, end_node);
    ROS_DEBUG_STREAM_NAMED("path_creation","Received node path");
    std::vector<geometry_msgs::TransformStamped> segment;
    for (int i=0; i< nodes.size(); ++i) {
        ROS_DEBUG_STREAM_NAMED("path_creation","Converted node: "<<nodes[i]->toString());
        segment.push_back(nodes[i]->toMsg());
    }
    ROS_DEBUG_STREAM_NAMED("path_creation","Returning msg segment");
    return segment;
}

PathPlanner::PathPlanner(std::vector<int> visits) {
    visits.push_back(0);
    visits.insert(visits.begin(),0);

    std::vector<geometry_msgs::TransformStamped> landmarks = get_landmarks();

    for (int i=0; i<visits.size()-1; ++i){
        ROS_DEBUG_STREAM_NAMED("segment_planner","Planning segment " << i);
        ROS_DEBUG_STREAM_NAMED("segment_planner","-- Start " << landmarks[i] );
        ROS_DEBUG_STREAM_NAMED("segment_planner","-- End " << landmarks[i+1] );
        geometry_msgs::TransformStamped start = landmarks[visits[i]];
        geometry_msgs::TransformStamped end = landmarks[visits[i+1]];
        std::vector<geometry_msgs::TransformStamped> segment = get_segment(start, end);
        ROS_DEBUG_STREAM_NAMED("path_creation","Received MSG segment " << i);
        path.push_back(segment);
    }
}

