#include <ros/ros.h>
#include <controller/JoyAngleIntegrator.h>
#include <controller/Triangle.h>
#include <controller/Arbitrator.h>

class Arbitrator
{
public:
  Arbitrator();

private:
  void joystickCallback(const controller::JoyAngleIntegrator::ConstPtr& joystick);
  void triangleCallback(const controller::Triangle::ConstPtr& triangle);

  ros::NodeHandle n;
 
  ros::Publisher  arbitrator_pub;
  ros::Subscriber joystick_sub;
  ros::Subscriber triangle_sub;

  bool joystickControl;
  bool power;
};

Arbitrator::Arbitrator(void)
{
  arbitrator_pub = n.advertise<controller::Arbitrator>("controller/Arbitrator", 10);
  joystick_sub = n.subscribe<controller::JoyAngleIntegrator>("controller/JoyAngleIntegrator", 10, &Arbitrator::joystickCallback, this);
  triangle_sub = n.subscribe<controller::Triangle>("controller/Triangle", 10, &Arbitrator::triangleCallback, this);

  joystickControl = true;
  power = false;
}

void Arbitrator::joystickCallback(const controller::JoyAngleIntegrator::ConstPtr& joystick)
{
  controller::Arbitrator msg;
  joystickControl = joystick->joystickControl;
  power = joystick->power;
  if(joystickControl)
  {
    msg.power = joystick->power;
    msg.x_translation = joystick->x_translation;
    msg.y_translation = joystick->y_translation;
    msg.lift = joystick->lift;
    msg.angle = joystick->angle;
    arbitrator_pub.publish(msg);
  }
}

void Arbitrator::triangleCallback(const controller::Triangle::ConstPtr& triangle)
{
    controller::Arbitrator msg;
    if(!joystickControl && power)
    {
      arbitrator_pub.publish(msg);
    }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "arbitrator");
  Arbitrator arbitrator;

  ros::spin();
}
