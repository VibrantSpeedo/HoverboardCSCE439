#include <ros/ros.h>
#include <controller/HovercraftControl.h>
#include <sensor_msgs/Joy.h>

class JoyStick
{
public:
  JoyStick();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  
  ros::NodeHandle n;

  ros::Publisher control_pub;
  ros::Subscriber joy_sub;

  bool hovercraftOn;
  uint8_t lastStartValue;
};

JoyStick::JoyStick(void)
{
  control_pub = n.advertise<controller::HovercraftControl>("controller/HovercraftControl", 1);
  joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, &JoyStick::joyCallback, this);
  
  hovercraftOn = false;
  lastStartValue = 0;
}

void JoyStick::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  //If Start button is pressed, toggle state of hovercraft
  if(joy->buttons[7] == 1 && lastStartValue == 0)
  {
    hovercraftOn = !hovercraftOn;
  }
  lastStartValue = joy->buttons[7];

  controller::HovercraftControl hovercraftControl;
  if(hovercraftOn)
  {
    hovercraftControl.power = 1;
    hovercraftControl.x_translation = joy->axes[3];
    hovercraftControl.y_translation = joy->axes[4];
    hovercraftControl.rotation = joy->axes[0];
    hovercraftControl.red_led = joy->buttons[1];
    hovercraftControl.green_led = joy->buttons[0];
  }
  else
  {
    hovercraftControl.power = 0;
  }
  control_pub.publish(hovercraftControl);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joystick");
  JoyStick joystick;

  ros::spin();
}
