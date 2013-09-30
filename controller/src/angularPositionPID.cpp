#include <ros/ros.h>
#include <hoverboard/GyroRaw.h>
#include <hovercraft/Gyro.h>
#include <controller/HovercraftControl.h>
#include <hovercraft/Thruster.h>
#include <cmath>

class AngularPositionPID
{
public:
  AngularPositionPID();
  float rate;
  float angle;
  double targetAngle;
  double pValue;
  double dValue;
  bool isHovercraftOn;
  float lift;
  double lastError;

private:
  void gyroRawCallback(const hoverboard::GyroRaw::ConstPtr& data);
  void gyroCallback(const hovercraft::Gyro::ConstPtr& data);
  void controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl);
  
  ros::NodeHandle n;
  ros::Publisher thruster_pub;
  ros::Subscriber joy_sub;
  ros::Subscriber gyro_raw_sub;
  ros::Subscriber gyro_sub;
};

AngularPositionPID::AngularPositionPID(void)
{
  gyro_raw_sub = n.subscribe("hoverboard/GyroRaw",1,&AngularPositionPID::gyroRawCallback,this);
  //gyro_sub = n.subscribe("hovercraft/Gyro",1,&AngularPositionPID::gyroCallback,this);
  joy_sub = n.subscribe<controller::HovercraftControl>("controller/HovercraftControl", 1, &AngularPositionPID::controllerCallback, this);
  thruster_pub = n.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  targetAngle = 0;
  pValue = .5;
  n.param("AngularPositionPID/p_value",pValue,pValue);
  n.setParam("AngularPositonPID/p_value",pValue);
  dValue = .5;
  n.param("AngularPositionPID/d_value",dValue,dValue);
  n.setParam("AngularPositonPID/d_value",dValue);
  targetAngle = 0;
  n.param("AngularPositionPID/target_angle",targetAngle,targetAngle);
  n.setParam("AngularPositionPID/target_angle",targetAngle);
  isHovercraftOn = false;
  lastError = 0;
}

void AngularPositionPID::gyroRawCallback(const hoverboard::GyroRaw::ConstPtr& gyro){
  float r, forwardsAngle, backwardsAngle, error;
  rate = gyro->rate;
  angle = gyro->angle;
  hovercraft::Thruster thruster;
  if(isHovercraftOn)
  {
    thruster.lift = lift;

    if(angle > targetAngle){
      backwardsAngle = angle - targetAngle;
      forwardsAngle = fabs(angle - (targetAngle + 360));

      if(backwardsAngle < forwardsAngle){
        error = targetAngle - angle;
        float p = pValue*(targetAngle - angle);
        float d = dValue*(error - lastError);
        lastError = error;
        r = fabs((p + d) / 360);
        if (r > 1)
          r=1;  
      thruster.thruster5 = r;
      }
      else if(forwardsAngle <= backwardsAngle){
        error = (targetAngle+360) - angle;
        float p = pValue*(error);
        float d = dValue*(error - lastError);
        lastError = error;
        r = fabs((p + d) / 360);
        if (r > 1)
          r=1;  
        thruster.thruster4 = r;
      }
    }
    else if(targetAngle >= angle){
      forwardsAngle = fabs(angle - targetAngle);
      backwardsAngle = (angle + 360) - targetAngle;
      
      if(forwardsAngle <= backwardsAngle){
        error = targetAngle - angle;
        float p = pValue*(targetAngle - angle);
        float d = dValue*(error - lastError);
        lastError = error;
        r = fabs((p + d) / 360);
        if (r > 1)
          r=1;  
        
        thruster.thruster4 = r;
      }
      else if(backwardsAngle < forwardsAngle){
        error = targetAngle - (angle+360);
        float p = pValue*(error);
        float d = dValue*(error - lastError);
        lastError = error;
        r = fabs((p + d) / 360);
        if (r > 1)
          r=1;  

        thruster.thruster5 = r;
      }
    }
  }
  else 
  {
    thruster.thruster4 = 0; //Right
    thruster.thruster5 = 0; //Left
  }
  thruster_pub.publish(thruster);
}

void AngularPositionPID::gyroCallback(const hovercraft::Gyro::ConstPtr& gyro){
  float r;
  rate = gyro->rate;
  angle = gyro->angle;
  hovercraft::Thruster thruster;
  if(isHovercraftOn)
  {
    thruster.lift = lift;

    r = pValue*( (targetAngle + (float)(360*((int)(angle/360)))) - angle) / 360;
    if(r > 0)
    {
      if(r > 1) r = 1;
      thruster.thruster4 = r;
    }
    else
    {
      r = fabs(r);
      if(r > 1) r = 1;
      thruster.thruster5 = r;
    } 
  }
  else 
  {
    thruster.thruster4 = 0; //Right
    thruster.thruster5 = 0; //Left
  }
  thruster_pub.publish(thruster);
}

void AngularPositionPID::controllerCallback(const controller::HovercraftControl::ConstPtr& hovercraftControl)
{
  isHovercraftOn = hovercraftControl->power;
  lift = hovercraftControl->lift;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "angularPositionPID");
  AngularPositionPID angularPositionPID;

  ros::spin();
}
