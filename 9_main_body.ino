void setup() {
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE);
  HCPCA9685.Sleep(false);

  pinMode(slow, INPUT);
  pinMode(medium, INPUT);
  pinMode(fast, INPUT);
  pinMode(walk_straight, INPUT);
  pinMode(turn_left, INPUT);
  pinMode(turn_right, INPUT);
  pinMode(walk_backwards, INPUT);

  //finding values for middle position of hips
  HCPCA9685.Servo(14, servo14_start_pos);
  HCPCA9685.Servo(12, servo12_start_pos);
  HCPCA9685.Servo(10, servo10_start_pos);
  HCPCA9685.Servo(8, servo8_start_pos);
  HCPCA9685.Servo(6, servo6_start_pos);
  HCPCA9685.Servo(4, servo4_start_pos);

  // finding ground touch of legtips
  HCPCA9685.Servo(15, servo15_start_pos);
  HCPCA9685.Servo(13, servo13_start_pos);
  HCPCA9685.Servo(11, servo11_start_pos);
  HCPCA9685.Servo(9, servo9_start_pos);
  HCPCA9685.Servo(7, servo7_start_pos);
  HCPCA9685.Servo(5, servo5_start_pos);

  delay(3000);
  
  digitalWrite(slow, HIGH);
  digitalWrite(walk_straight, HIGH);

  
  

}

void loop() {
  //LegTurn1.UpdateRight(4, 5, servo4_start_pos, servo5_start_pos);
  Straight_walker.Gait();
}
