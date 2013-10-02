#include <ros/ros.h>
#include <hoverboard/GyroRaw.h>
#include <hovercraft/Gyro.h>
#include <controller/Arbitrator.h>
#include <controller/AngularPositionPID.h>
#include <cmath>

#define MAX_ROTATE_RATE 500

class AngularPositionPID
{
public:
    AngularPositionPID();
    float rate;
    float angle;
    double pValue;
    double dValue;
    double lastError;
    
private:
    void gyroRawCallback(const hoverboard::GyroRaw::ConstPtr& data);
    void gyroCallback(const hovercraft::Gyro::ConstPtr& data);
    void joystickCallback(const controller::Arbitrator::ConstPtr& arbitrator);
    
    ros::NodeHandle n;
    ros::Publisher pid_pub;
    ros::Subscriber joy_sub;
    ros::Subscriber gyro_raw_sub;
    ros::Subscriber gyro_sub;
};

AngularPositionPID::AngularPositionPID(void)
{
    //gyro_raw_sub = n.subscribe("hoverboard/GyroRaw",10,&AngularPositionPID::gyroRawCallback,this);
    gyro_sub = n.subscribe("hovercraft/Gyro",10,&AngularPositionPID::gyroCallback,this);
    joy_sub = n.subscribe<controller::Arbitrator>("controller/Arbitrator", 10, &AngularPositionPID::joystickCallback, this);
    pid_pub = n.advertise<controller::AngularPositionPID>("controller/AngularPositionPID", 10);
    
    pValue = .5;
    n.param("AngularPositionPID/p_value",pValue,pValue);
    n.setParam("AngularPositonPID/p_value",pValue);
    dValue = .5;
    n.param("AngularPositionPID/d_value",dValue,dValue);
    n.setParam("AngularPositonPID/d_value",dValue);
    
    rate = 0;
    angle = 0;
    lastError = 0;
}

void AngularPositionPID::gyroRawCallback(const hoverboard::GyroRaw::ConstPtr& gyro){
    rate = gyro->rate;
    angle = gyro->angle;
}

void AngularPositionPID::gyroCallback(const hovercraft::Gyro::ConstPtr& gyro){
    rate = gyro->rate;
    angle = gyro->angle;
}

void AngularPositionPID::joystickCallback(const controller::Arbitrator::ConstPtr& arbitrator)
{
    float r, forwardsAngle, backwardsAngle, error, p, d;
    float targetAngle = arbitrator->angle;
    
    controller::AngularPositionPID msg;
    msg.power = arbitrator->power;
    msg.x_translation = arbitrator->x_translation;
    msg.y_translation = arbitrator->y_translation;
    msg.lift = arbitrator->lift;
    
    if(arbitrator->power)
    {
        error - targetAngle - angle;
        p = pValue*(error);
        d = dValue*(error - lastError);
        lastError = error;
        r = fabs((p + d) / 360);
        
        // Limit the rate of rotation to the MAX_ROTATE_RATE defined above
        if (rate < MAX_ROTATE_RATE){
          if (r>1) r=1;
        }else{
          if (r>0) r=0;
        }
        
        // Rotate <Left or Right> if targetAngle <> angle
        if(error < 0){
            msg.thruster5 = r;
        }
        else if(error > 0){
            msg.thruster4 = r;
        }
        else {
            msg.thruster4 = 0;
            msg.thruster5 = 0;
        }
        /*
         if(angle > targetAngle){
            backwardsAngle = angle - targetAngle;
            forwardsAngle = fabs(angle - (targetAngle + 360));
            
            if(backwardsAngle < forwardsAngle){
                error = targetAngle - angle;
                p = pValue*(targetAngle - angle);
                d = dValue*(error - lastError);
                lastError = error;
                r = fabs((p + d) / 360);
                if (r > 1)
                r=1;
                msg.thruster5 = r;
            }
            else if(forwardsAngle <= backwardsAngle){
                error = (targetAngle+360) - angle;
                p = pValue*(error);
                d = dValue*(error - lastError);
                lastError = error;
                r = fabs((p + d) / 360);
                if (r > 1)
                r=1;
                msg.thruster4 = r;
            }
        }
        else if(targetAngle >= angle){
            forwardsAngle = fabs(angle - targetAngle);
            backwardsAngle = (angle + 360) - targetAngle;
            
            if(forwardsAngle <= backwardsAngle){
                error = targetAngle - angle;
                p = pValue*(targetAngle - angle);
                d = dValue*(error - lastError);
                lastError = error;
                r = fabs((p + d) / 360);
                if (r > 1)
                r=1;
                
                msg.thruster4 = r;
            }
            else if(backwardsAngle < forwardsAngle){
                error = targetAngle - (angle+360);
                p = pValue*(error);
                d = dValue*(error - lastError);
                lastError = error;
                r = fabs((p + d) / 360);
                if (r > 1)
                r=1;  
                
                msg.thruster5 = r;
            }
        }
         */
    }
    pid_pub.publish(msg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "angularPositionPID");
    AngularPositionPID angularPositionPID;
    
    ros::spin();
}
