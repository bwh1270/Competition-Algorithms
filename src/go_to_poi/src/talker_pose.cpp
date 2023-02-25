#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_pose");
    ros::NodeHandle nh;

    ros::Publisher pose_pub = nh.advertise<geometry_msgs::PointStamped>("red/position", 10);

    ROS_INFO("Current position is publishing now!!");
    while (ros::ok())
    {
        geometry_msgs::PointStamped pose_msg;
        pose_msg.point.x = 2.;
        pose_msg.point.y = 10;
        pose_msg.point.z = 2;

        pose_pub.publish(pose_msg);
        ros::spinOnce();
    }
    return 0;
}