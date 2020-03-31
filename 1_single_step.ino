/*class Leg{
  
  int servo1;    // the servo PCA pin numbers
  int servo2;
  int hip_start;  // servo starting positions
  int knee_start;
  
  public:
  void set_values(int,int,int,int);
  
  
  
  
};

void Leg::set_values (int hip_servo, int knee_servo, int hip_home, int knee_home){
  servo1 = hip_servo;
  servo2 = knee_servo;
  hip_start = hip_home;
  knee_start = knee_home;
  
} */


class LegTurn
{
  
  float increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate;
  unsigned long lastUpdate1;// last update of position
  float hip_pos;              // current servo positions
  int knee_pos;
  int cycle_counter;
  public: 
     
     
  
   
  
  LegTurn(int interval) //interval determines overall speed 1 = fast, 10 = slow more than 10 becomes very jittery
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void UpdateRight(int hip_servo, int knee_servo, int hip_home, int knee_home) //which leg to move
  { 
    if(cycle_counter == 0){
      hip_pos=hip_home;
      knee_pos=knee_home;
      cycle_counter++;
    }
    else if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      hip_pos += increment;
      HCPCA9685.Servo(hip_servo, hip_pos); // turn leg
      Serial.println((String)"hip servo is at: " + hip_pos + " " + "knee servo is at: " + knee_pos);
      if (hip_pos >= (hip_home + 60)) // go to 45 deg
      {
        
        increment = -0.1;
        knee_pos = knee_home + 50;
        HCPCA9685.Servo(knee_servo, knee_pos); //leg down
      }
      else if (hip_pos <= (hip_home - 60)){ //go to 135 deg

        increment= 1;
        knee_pos = knee_home - 50;
        HCPCA9685.Servo(knee_servo, knee_pos); // leg up
      }
    }
  }
  void UpdateLeft(int hip_servo, int knee_servo, int hip_home, int knee_home) //which leg to move
  { if(cycle_counter == 0){
      hip_pos=hip_home;
      knee_pos=knee_home;
      cycle_counter++;
  }
    if((millis() - lastUpdate1) > updateInterval)  // time to update
    {
      lastUpdate1 = millis();
      hip_pos += increment;
      HCPCA9685.Servo(hip_servo, hip_pos); // turn leg
      Serial.println((String)"hip servo2 is at: " + hip_pos + " " + "knee servo2 is at: " + knee_pos);
      if (hip_pos >= (hip_home + 60)) // go to 45 deg
      {
        
        increment = -1;
        knee_pos = knee_home + 50;
        HCPCA9685.Servo(knee_servo, knee_pos); //leg up
      }
      else if (hip_pos <= (hip_home - 60)){ //go to 135 deg

        increment= 0.1;
        knee_pos = knee_home - 50;
        HCPCA9685.Servo(knee_servo, knee_pos); // leg down
      }
    }
  }

};
