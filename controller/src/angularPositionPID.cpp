#include <ros/ros.h>

class AngularPositionPID
{
public:
  AngularPositionPID();

private:
  ros::NodeHandle n;
};

AngularPositionPID::AngularPositionPID(void)
{

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "angularPositionPID");
  AngularPositionPID angularPositionPID;

  ros::spin();
}
