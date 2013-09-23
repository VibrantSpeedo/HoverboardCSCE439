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
  float rate;
};

Controller::Controller(void)
{
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  led_pub = n.advertise<hovercraft::LED>("hovercraft/LED", 1);
  joy_sub = n.subscribe<controller::HovercraftControl>("controller/HovercraftControl", 1, &Controller::controllerCallback, this);
  gyro_sub = n.subscribe("hovercraft/Gyro",1,&Controller::gyroCallback,this);
  rate = 0;
}

void Controller::gyroCallback(const hovercraft::Gyro::ConstPtr& gyroRaw){
  rate = gyroRaw->rate;
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

  if(hovercraftControl->power == 1)
  { 
    //left to right 1 to -1
    //up to down 1 to -1
    float x = (fabs((float)hovercraftControl->x_translation) > DEADZONE) ? hovercraftControl->x_translation : 0;
    float y = (fabs((float)hovercraftControl->y_translation) > DEADZONE) ? hovercraftControl->y_translation : 0;
    float rotation = (fabs((float)hovercraftControl->rotation) > DEADZONE) ? hovercraftControl->rotation : 0;
    
    float a1,b1,c1,a2,b2,c2; //linear system of equations
    float out1,out2,out3; //solution to system of equations
    float inMag, inAngle; //input vector angle and magnitude 
    
    thruster.lift = hovercraftControl->lift;
    
    inMag = sqrtf(-x*-x+y*y);
    inAngle = atan2f(y, -x);
    
    // angle will be in radians between 0 and 2*pi
    if (inAngle<0){
        inAngle = inAngle + 2*PI;
    }
    
    // angle between 0 and 90 or 330 and 360
    if((inAngle>=0 && inAngle<=1.5708) || (inAngle>=5.7596 && inAngle<=6.2832))
    {
        a1 = 1.0; //sin(90)
        b1 = -0.5; //sin(330)
        c1 = sin(inAngle);
        a2 = 0; //cos(90)
        b2 = 0.8660; //cos(330)
        c2 = cos(inAngle);
        
        out1 = (c1*b2-c2*b1)/(a1*b2-a2*b1);
        out2 = 0;
        out3 = (a1*c2-a2*c1)/(a1*b2-a2*b1);
    }
    // angle between 90 and 210
    else if(inAngle >= 1.5708 && inAngle<=3.6652)
    {
        a1 = 1.0; //sin(90)
        b1 = -0.5; //sin(210)
        c1 = sin(inAngle);
        a2 = 0; //cos(90)
        b2 = -0.8660; //cos(210)
        c2 = cos(inAngle);
        
        out1 = (c1*b2-c2*b1)/(a1*b2-a2*b1);
        out2 = (a1*c2-a2*c1)/(a1*b2-a2*b1);
        out3 = 0;
    }
    // angle between 210 and 330
    else if(inAngle >= 3.6652 && inAngle<=5.7596)
    {
        a1 = -0.5; //sin(210)
        b1 = -0.5; //sin(330)
        c1 = sin(inAngle);
        a2 = -0.8660; //cos(210)
        b2 = 0.8660; //cos(330)
        c2 = cos(inAngle);
        
        out1 = 0;
        out2 = (c1*b2-c2*b1)/(a1*b2-a2*b1);
        out3 = (a1*c2-a2*c1)/(a1*b2-a2*b1);
    }
    else
    {
        // not moving
        out1 = 0;
        out2 = 0;
        out3 = 0;
    }
    
    // Finding maximum to scale down to 1.
    float max = 0;
    
    if(out1>out2){
        if(out1>out3){
            max = out1;
        }
    }
    else if(out2>out1){
        if(out2>out3){
            max = out2;
        }
    }
    else if(out3>out2){
        if(out3>out1){
            max = out3;
        }
    }

    thruster.thruster1 = inMag*(out1/max);
    thruster.thruster2 = inMag*(out2/max);
    thruster.thrutser3 = inMag*(out3/max);
    /*
    if(x>0)
    {
       thruster.thruster1 = x*0.5;
       thruster.thruster2 = x;
    }
    else if(x<0)
    {
       thruster.thruster1 = -x*0.5;
       thruster.thruster3 = -x;
    }

    if(hovercraftControl->y_translation>0)
    {
      thruster.thruster1 += y;
    } 
    else if(y<0)
    {
      thruster.thruster2 += fabs(y);
      thruster.thruster3 += fabs(y);
    }
    
    if(thruster.thruster1 > 1.0)
    {
       thruster.thruster1 = 1.0;
    }
    
    if(thruster.thruster2 > 1.0)
    {
       thruster.thruster2 = 1.0;
    }
    
    if(thruster.thruster3 > 1.0)
    {
       thruster.thruster3 = 1.0;
    }
    */
    if(rotation>0)
    {
      thruster.thruster4 = rotation;
    } 
    else if(rotation<0)
    {
      thruster.thruster5 = fabs(rotation);
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
