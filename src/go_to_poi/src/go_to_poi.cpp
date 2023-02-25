#include <iostream>
#include <vector>

#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PointStamped.h"
#include "go_to_poi/poi.h"

using namespace std;

// Global variables
float current_pos[3];
vector<bool> waypoint_index;

// Function definition
void current_pos_callback(const geometry_msgs::PointStamped::ConstPtr &msg)
{
    current_pos[0] = msg->point.x;
    current_pos[1] = msg->point.y;
    current_pos[2] = msg->point.z;
}

void calculate_range(float *current, float *target, float *range)
{
    float delta_x, delta_y, delta_z;
    delta_x = current[0] - target[0];
    delta_y = current[1] - target[1];
    delta_z = current[2] - target[2];
    *range = (delta_x * delta_x) + (delta_y * delta_y) + (delta_z * delta_z);
}

void poi_array_sub(const go_to_poi::poi::ConstPtr &msg)
{
    int poi_len = msg->poi.size();
    waypoint_index.resize(poi_len);
    float range;
    float min_range = 10e9f;
    float temp_poi[3];
    int i;

    for (i = 0; i < poi_len; ++i)
    {
        temp_poi[0] = msg->poi[i].x;
        temp_poi[1] = msg->poi[i].y;
        temp_poi[2] = msg->poi[i].z;
        calculate_range(current_pos, temp_poi, &range);

        if (min_range >= range)
        {
            min_range = range;
            waypoint_index[i] = true;
        }
    }
    cout << range << "\n"
         << waypoint_index[i] << endl;
}

// Main Function
int main(int argc, char **argv)
{
    ros::init(argc, argv, "go_to_poi");
    ros::NodeHandle nh;

    ros::Subscriber current_pos_sub = nh.subscribe("red/position", 10, &current_pos_callback);
    ros::Subscriber poi_arrary_sub = nh.subscribe("poi", 10, &poi_array_sub);

    ROS_INFO("vehicle starts!!");
    ros::spin();
    return 0;
}