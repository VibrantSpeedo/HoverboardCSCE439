#include <ros/ros.h>

class ReactiveControl
{
public:
  ReactiveControl();

private:
  ros::NodeHandle n;
};

ReactiveControl::ReactiveControl(void)
{

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "reactiveControl");
  ReactiveControl reactiveControl;

  ros::spin();
}
