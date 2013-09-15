#include <ros/ros.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/LED.h>
#include <hovercraft/Gyro.h>
#include <controller/HovercraftControl.h>
#include <math.h>

#define DEADZONE .15

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

class Controller
{
public:
  Controller();

private:
  void controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl);
  void gyroCallback(const hovercraft::Gyro::ConstPtr& data);

  ros::NodeHandle n;

  ros::Publisher thruster_pub;
  ros::Publisher led_pub;
  ros::Subscriber joy_sub;
  ros::Subscriber gyro_sub;

  bool hovercraftOn;
  uint8_t lastStartValue;
};

Controller::Controller(void)
{
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  led_pub = n.advertise<hovercraft::LED>("hovercraft/LED", 1);
  joy_sub = n.subscribe<controller::HovercraftControl>("controller/HovercraftControl", 1, &Controller::controllerCallback, this);
  gyro_sub = n.subscribe("hovercraft/Gyro",1,&Controller::gyroCallback,this);
  
  hovercraftOn = false;
  lastStartValue = 0;
}

void Controller::gyroCallback(const hovercraft::Gyro::ConstPtr& gyroRaw){

}

void Controller::controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl)
{
  hovercraft::Thruster thruster;
  hovercraft::LED led;

  thruster.lift = 0;
  //Translational Thrusters Location
  thruster.thruster1 = 0; //Back
  thruster.thruster2 = 0; //Right
  thruster.thruster3 = 0; //Left
  //Rotational Thrusters
  thruster.thruster4 = 0; //Right
  thruster.thruster5 = 0; //Left
  //Unused
  thruster.thruster6 = 0; //

  if(hovercraftControl->power)
  { 
    //left to right 1 to -1
    //up to down 1 to -1
    float x = (abs(hovercraftControl->x_translation) > DEADZONE) ? hovercraftControl->x_translation : 0;
    float y = (abs(hovercraftControl->y_translation) > DEADZONE) ? hovercraftControl->y_translation : 0;
    float rotation = (abs(hovercraftControl->rotation) > DEADZONE) ? hovercraftControl->rotation : 0;

    thruster.lift = .6;

    if(y>0)
    {
      thruster.thruster1 = y;
    } 
    else if(y<0)
    {
      thruster.thruster2 = abs(y);
      thruster.thruster3 = abs(y);
    }
    
    if(rotation>0)
    {
      thruster.thruster4 = rotation;
    } 
    else if(rotation<0)
    {
      thruster.thruster5 = abs(rotation);
    }
    
    led.led33_red = hovercraftControl->red_led;
    led.led33_green = hovercraftControl->green_led;
  }

  thruster_pub.publish(thruster);
  led_pub.publish(led);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "controller");
  Controller controller;

  ros::spin();
}
