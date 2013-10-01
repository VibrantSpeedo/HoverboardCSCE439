#include <ros/ros.h>
#include <controller/JoyAngleIntegrator.h>
#include <controller/JoyStick.h>

class JoyAngleIntegrator
{
public:
  JoyAngleIntegrator();

private:
  void joystickCallback(const controller::JoyStick::ConstPtr& joystick);
  void updateSetpoints(const ros::TimerEvent& e);
  ros::Timer timer;
  ros::NodeHandle n;

  ros::Publisher  setpoint_pub;
  ros::Subscriber joystick_sub;
  
  controller::JoyAngleIntegrator msg;
};

JoyAngleIntegrator::JoyAngleIntegrator(void)
{
  setpoint_pub = n.advertise<controller::JoyAngleIntegrator>("controller/JoyAngleIntegrator", 10);
  joystick_sub = n.subscribe<controller::JoyStick>("controller/JoyStick", 10, &JoyAngleIntegrator::joystickCallback, this);
  timer = n.createTimer(ros::Duration(0.1), &JoyAngleIntegrator::updateSetpoints, this );
   
  msg.x_translation = 0;
  msg.y_translation = 0;
  msg.lift = 0;
  msg.angle = 0;
  msg.joystickControl = true;
}

void JoyAngleIntegrator::joystickCallback(const controller::JoyStick::ConstPtr& joystick)
{
  msg.power = joystick->power;
  msg.x_translation = joystick->x_translation;
  msg.y_translation = joystick->y_translation;
  msg.lift = joystick->lift;
  msg.joystickControl = joystick->joystickControl;
  
  if(joystick->angle >= 0)
  {
    msg.angle = joystick->angle;
  } 
  else if(joystick->add90)
  {
    msg.angle += 90;
    if(msg.angle >= 360) msg.angle -= 360;
  }
  else if(joystick->subtract90)
  {
    msg.angle -= 90;
    if(msg.angle < 0) msg.angle += 360;
  }
  else
  {

  }
}

void JoyAngleIntegrator::updateSetpoints(const ros::TimerEvent& e){
  setpoint_pub.publish(msg);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "joyAngleIntegrator");
  JoyAngleIntegrator joyAngleIntegrator;

  ros::spin();
}
