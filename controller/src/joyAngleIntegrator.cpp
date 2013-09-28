#include <ros/ros.h>

class JoyAngleIntegrator
{
public:
  JoyAngleIntegrator();

private:
  ros::NodeHandle n;
};

JoyAngleIntegrator::JoyAngleIntegrator(void)
{

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "joyAngleIntegrator");
  JoyAngleIntegrator joyAngleIntegrator;

  ros::spin();
}
