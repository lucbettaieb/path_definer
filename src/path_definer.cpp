/*
* path_definer
* Luc Bettaieb
* bettaieb@case.edu
*/

#include <ros/ros.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>

ros::Subscriber sub_pose_;
ros::Publisher pub_poseArr_;

geometry_msgs::PoseArray poseArr_;

void poseCB(const geometry_msgs::PoseStamped &pose){
	poseArr_.poses.push_back(pose.pose);

	pub_poseArr_.publish(poseArr_);
}

int main(int argc, char** argv){
	ros::init(argc, argv, "path_definer");
	ros::NodeHandle nh;

	poseArr_.header.seq = 1;
	poseArr_.header.stamp = ros::Time().now();
	poseArr_.header.frame_id = "map";

	sub_pose_ = nh.subscribe("/move_base_simple/goal", 10, poseCB);
	pub_poseArr_ = nh.advertise<geometry_msgs::PoseArray>("/move_base_simple/goalArr", 1);
	ros::spin();
}