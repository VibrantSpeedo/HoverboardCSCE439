#include <ros/ros.h>

class Arbitrator
{
public:
  Arbitrator();

private:
  ros::NodeHandle n;
};

Arbitrator::Arbitrator(void)
{

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "arbitrator");
  Arbitrator arbitrator;

  ros::spin();
}
