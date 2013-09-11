#include <ros/ros.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/LED.h>
#include <sensor_msgs/Joy.h>

class JoyStick
{
public:
  JoyStick();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  
  ros::NodeHandle n;

  ros::Publisher thruster_pub;
  ros::Publisher led_pub;
  ros::Subscriber joy_sub;

  bool hovercraftOn;
  uint8_t lastStartValue;
};

JoyStick::JoyStick(void)
{
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  led_pub = n.advertise<hovercraft::LED>("hovercraft/LED", 1);
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

  hovercraft::Thruster thruster;
  hovercraft::LED led;
  if(hovercraftOn)
  {
    thruster.lift = .2;
    thruster.thruster1 = 0;
    thruster.thruster2 = 0;
    thruster.thruster3 = 0;
    thruster.thruster4 = 0;
    thruster.thruster5 = 0;
    thruster.thruster6 = 0;
    
    led.led33_red = joy->buttons[1];
    led.led33_green = joy->buttons[0];
  }
  else
  {
    thruster.lift = 0;
    thruster.thruster1 = 0;
    thruster.thruster2 = 0;
    thruster.thruster3 = 0;
    thruster.thruster4 = 0;
    thruster.thruster5 = 0;
    thruster.thruster6 = 0;

    led.led33_red = 0;
    led.led33_green = 0;
  }
  thruster_pub.publish(thruster);
  led_pub.publish(led);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joystick");
  JoyStick joystick;

  ros::spin();
}
