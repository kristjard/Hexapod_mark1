


LegTurn LegTurn1(set_speed);
LegTurn LegTurn2(set_speed);
LegTurn LegTurn3(set_speed);
LegTurn LegTurn4(set_speed);
LegTurn LegTurn5(set_speed);
LegTurn LegTurn6(set_speed);



class Tripod
{
  
  
  public:
  unsigned long take_a_step;
  int Speed_setter(){
    if(digitalRead(slow)){
      set_speed=10;
    }
    if(digitalRead(medium)){
      set_speed=5;
    }
    if(digitalRead(fast)){
      set_speed=1;
    }
  }
  void Gait()
  {
    
    if((millis() - take_a_step) <= 3000)
    {
      while( 500<= (millis() - take_a_step) <=3000)
      {
        Serial.println((String)" take a tep = " + take_a_step + ", millis= " + millis() + ", stepping leg 1, 4, 5");
        LegTurn1.UpdateRight(4, 5, servo4_start_pos, servo5_start_pos);
        LegTurn4.UpdateLeft(10, 11, servo10_start_pos, servo11_start_pos);    
        LegTurn5.UpdateRight(12, 13, servo12_start_pos, servo13_start_pos);
        if(millis()-take_a_step>3000){
          
          break;
        }
        
      }
    }
    else
    {
      while(3500 <= (millis() - take_a_step) <= 6000 ){
        Serial.println((String)" take a tep = " + take_a_step + ", millis= " + millis() + ", stepping leg 2, 3, 6");
        LegTurn2.UpdateLeft(6, 7, servo6_start_pos, servo7_start_pos);
        LegTurn3.UpdateRight(8, 9, servo8_start_pos, servo9_start_pos);
        LegTurn6.UpdateLeft(14, 15, servo14_start_pos, servo15_start_pos);
        if(millis()-take_a_step>6000){
          take_a_step=millis();
          break;
        }
        
        
      }
    }   
  }
};

Tripod Straight_walker;
