#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "go_to_poi/poi.h"

// Global Variables
float tile_poses[3][3] = {
	{7.56, 8.32, 0.7854},
	{7.57, 14.60, -0.7854},
	{3.00, 43.36, -1.5707}};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker_poi");
	ros::NodeHandle nh;

	bool shoud_latch = true;
	ros::Publisher poi_pub = nh.advertise<go_to_poi::poi>("poi", 10, shoud_latch);

	go_to_poi::poi PoIArray;
	PoIArray.poi.resize(3);
	for (int i = 0; i < 3; ++i)
	{
		geometry_msgs::Point point_msg;
		point_msg.x = tile_poses[i][0];
		point_msg.y = tile_poses[i][1];
		point_msg.z = tile_poses[i][2];
		PoIArray.poi[i] = point_msg;
	}

	ROS_INFO("PoI is publishing now!!");
	poi_pub.publish(PoIArray);
	ros::spin();
	return 0;
}