#include <ros/ros.h>
#include <controller/JoyStick.h>
#include <sensor_msgs/Joy.h>

#define ButtonCount 15
#define ButtonA 0
#define ButtonB 1
#define ButtonX 2
#define ButtonY 3
#define LB 4
#define RB 5
#define Back 6
#define Start 7
#define DPadLeft 11
#define DPadRight 12
#define DPadUp 13
#define DPadDown 14

#define LeftJoystickX 0
#define RightJoystickX 3
#define RightJoystickY 4

class JoyStick
{
public:
  JoyStick();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  
  ros::NodeHandle n;

  ros::Publisher  joy_pub;
  ros::Subscriber joy_sub;

  float lift;
  bool hovercraftOn;
  bool joystickControl;
  uint8_t lastButtonValues[ButtonCount];
};

JoyStick::JoyStick(void)
{
  joy_pub = n.advertise<controller::JoyStick>("controller/JoyStick", 10);
  joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, &JoyStick::joyCallback, this);
  
  lift = 0.4;
  hovercraftOn = false;
  joystickControl = true;
  for(int i = 0; i < ButtonCount; i++)
  {
    lastButtonValues[i] = 0;
  }
}

void JoyStick::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  //If Start button is pressed, toggle state of hovercraft
  if(joy->buttons[Start] == 1 && lastButtonValues[Start] == 0)
  {
    hovercraftOn = !hovercraftOn;
  }
  if(joy->buttons[Back] == 1 && lastButtonValues[Back] == 0)
  {
    joystickControl = !joystickControl;
  }
  if(!hovercraftOn) joystickControl = true;
  controller::JoyStick msg;
  msg.power = hovercraftOn;
  msg.rotation = 0;
  msg.x_translation = 0;
  msg.y_translation = 0;
  msg.lift = 0;
  msg.angle = -1;
  msg.add90 = 0;
  msg.subtract90 = 0;
  msg.joystickControl = joystickControl;

  if(hovercraftOn)
  {
    if(joy->buttons[ButtonX] == 1 && lastButtonValues[ButtonX] == 0)
    {
      lift -= 0.1;
    }
    if(joy->buttons[ButtonY] == 1 && lastButtonValues[ButtonY] == 0)
    {
      lift += 0.1;
    }
    if(lift > 1)
    {
      lift = 1;
    }
    else if (lift < 0)
    {
       lift = 0;
    }
    
    if(joy->buttons[LB] == 1 && lastButtonValues[LB] == 0)
    {
      msg.subtract90 = true;
    }
    else if(joy->buttons[RB] == 1 && lastButtonValues[RB] == 0)
    {
      msg.add90 = true;
    }
    
    if(joy->buttons[DPadRight] == 1 && lastButtonValues[DPadRight] == 0)
    {
      msg.angle = 0;
    }
    else if(joy->buttons[DPadUp] == 1 && lastButtonValues[DPadUp] == 0)
    {
      msg.angle = 90;
    }
    else if(joy->buttons[DPadLeft] == 1 && lastButtonValues[DPadLeft] == 0)
    {
      msg.angle = 180;
    }
    else if(joy->buttons[DPadDown] == 1 && lastButtonValues[DPadDown] == 0)
    {
      msg.angle = 270;
    }

    msg.x_translation = joy->axes[RightJoystickX];
    msg.y_translation = joy->axes[RightJoystickY];
    msg.rotation = joy->axes[LeftJoystickX];
    msg.lift = lift;
    //msg.red_led = joy->buttons[ButtonA];
    //msg.green_led = joy->buttons[ButtonB];
  }

  for(int i = 0; i < ButtonCount; i++)
  {
    lastButtonValues[i] = joy->buttons[i];
  }

  joy_pub.publish(msg);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joystick");
  JoyStick joystick;

  ros::spin();
}
