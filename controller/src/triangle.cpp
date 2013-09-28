#include <ros/ros.h>

class Triangle
{
public:
  Triangle();

private:
  ros::NodeHandle n;
};

Triangle::Triangle(void)
{

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "triangle");
  Triangle triangle;

  ros::spin();
}
