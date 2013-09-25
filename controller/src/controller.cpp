#include <ros/ros.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/LED.h>
#include <hovercraft/Gyro.h>
#include <controller/HovercraftControl.h>
#include <cmath>

#define DEADZONE .15
#define MAX_RATE 619
#define MIN_RATE -363
#define PI 3.14159

class Controller
{
public:
  Controller();
  ros::Publisher thruster_pub;
  hovercraft::Thruster thruster;
  float rate;
  bool turningLeft;
  bool turningRight;
  
private:
  void controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl);
  void gyroCallback(const hovercraft::Gyro::ConstPtr& data);

  ros::NodeHandle n;

  ros::Publisher led_pub;
  ros::Subscriber joy_sub;
  ros::Subscriber gyro_sub;
};

Controller::Controller(void)
{
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  led_pub = n.advertise<hovercraft::LED>("hovercraft/LED", 1);
  joy_sub = n.subscribe<controller::HovercraftControl>("controller/HovercraftControl", 1, &Controller::controllerCallback, this);
  gyro_sub = n.subscribe("hovercraft/Gyro",1,&Controller::gyroCallback,this);
  rate = 0;
  turningRight = false;
  turningLeft = false;
}

void Controller::gyroCallback(const hovercraft::Gyro::ConstPtr& gyroRaw){
  rate = gyroRaw->rate;
}

void Controller::controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl)
{
  //hovercraft::Thruster thruster;
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
  
  if(hovercraftControl->power == 1)
  { 
    float x = -(hovercraftControl->x_translation);
    float y = hovercraftControl->y_translation;
    float rotation = (fabs((float)hovercraftControl->rotation) > DEADZONE) ? hovercraftControl->rotation : 0;
    
    thruster.lift = hovercraftControl->lift;
    
    if(fabs(x) > DEADZONE || fabs(y) > DEADZONE)
    {
      float angle = atan2(y, x);
      if(angle < 0)
      {
        angle += 2*PI;
      }
      
      float a = 0;
      float b = 0;
      float c = 0;

      angle *= 180/PI;
      /*if(angle < 95 && angle > 85)
      {
        a = 1;
      }
      else if(angle < 215 && angle > 205)
      {
        b = 1;
      }
      else if(angle < 335 && angle > 325)
      {
        c = 1;
      }
      else*/ if(angle >= 90 && angle < 210)
      {
        b = -2*x/sqrt(3);
        a = y + b/2;
      } 
      else if (angle >= 210 && angle < 330)
      {
        c = (x - sqrt(3)*y)/sqrt(3);
        b = -2*y-c;
      }
      else 
      {
        c = 2*x/sqrt(3);
        a = y + c/2;
      }
      
      if(a < 0) a = 0; if(a > 1) a = 1;
      if(b < 0) b = 0; if(b > 1) b = 1;
      if(c < 0) c = 0; if(c > 1) c = 1;

      thruster.thruster1 = a;
      thruster.thruster2 = b;
      thruster.thruster3 = c;
      thruster.angle = angle;   
    }
    
    if(rotation>0)
    {
      thruster.thruster4 = rotation;
      thruster.thruster5 = 0;
      turningLeft = true;
    } 
    else if(rotation<0)
    {
      thruster.thruster4 = 0;
      thruster.thruster5 = fabs(rotation);
      turningRight = true;
    }
    else 
    {
      turningRight = false;
      turningLeft = false;
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

  ros::Rate r(10);
  
  while(ros::ok())
  {	
    if(controller.turningLeft){	
      if(controller.rate > (MAX_RATE-50))
      {
        controller.thruster.thruster5 =.1;
        //controller.thruster.thruster4 -= .02;
      } 
      else if(controller.thruster.thruster5 > 0)
      {
        controller.thruster.thruster5 = 0;
      }
      controller.thruster_pub.publish(controller.thruster);
    }
    else if(controller.turningRight)
    {   
      if(controller.rate < (MIN_RATE+50))
      {
        controller.thruster.thruster4 = .75;
        //controller.thruster.thruster5 -= .02;
      }
      else if(controller.thruster.thruster4 > 0)
      {
        controller.thruster.thruster4 = 0;
      }
      controller.thruster_pub.publish(controller.thruster);
    }
    else if(!controller.turningLeft && !controller.turningRight && (controller.thruster.thruster4 > 0 || controller.thruster.thruster5 > 0))
    {
      controller.thruster.thruster4 = 0;
      controller.thruster.thruster5 = 0;
      controller.thruster_pub.publish(controller.thruster);
    }
    ros::spinOnce();
    r.sleep();
  }
  
  //ros::spin();
}
