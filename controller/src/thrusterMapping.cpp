#include <ros/ros.h>
#include <hovercraft/Thruster.h>
#include <controller/AngularPositionPID.h>
#include <cmath>

#define DEADZONE .15
#define PI 3.14159

class ThrusterMapping
{
public:
  ThrusterMapping();
  
private:
  void joystickCallback(const controller::AngularPositionPID::ConstPtr& joystick);

  ros::NodeHandle n;

  ros::Publisher thruster_pub;
  ros::Subscriber joy_sub;
};

ThrusterMapping::ThrusterMapping(void)
{
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 10);
  joy_sub = n.subscribe<controller::AngularPositionPID>("controller/AngularPositionPID", 10, &ThrusterMapping::joystickCallback, this);
}

void ThrusterMapping::joystickCallback(const controller::AngularPositionPID::ConstPtr& joystick)
{
  hovercraft::Thruster thruster;

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
  
  if(joystick->power == 1)
  { 
    float x = -(joystick->x_translation);
    float y = joystick->y_translation;
    
    thruster.lift = joystick->lift;
    thruster.thruster4 = joystick->thruster4;
    thruster.thruster5 = joystick->thruster5;
    
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
      //thruster.angle = angle;   
    }
  }

  thruster_pub.publish(thruster);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ThrusterMapping");
  ThrusterMapping thrusterMapping;
  
  ros::spin();
}
