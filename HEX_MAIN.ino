#include "HCPCA9685.h" // lib for PCA9685 easy I2C control
#define I2CAdd 0x40

HCPCA9685 HCPCA9685(I2CAdd);  
// servo positions are 0-180 deg ~ 0-420 servo units, 1 deg ~ 2.3 sevo units

//pins
int slow = 10;
int medium = 9;
int fast = 8;
int walk_straight = 5;
int turn_left = 7;
int turn_right = 6;
int walk_backwards =4;

int set_speed=1; 

// leg home positions
// Leg 1
int servo4_start_pos = 300;
int servo5_start_pos = 255;
// Leg 2
int servo6_start_pos = 180;
int servo7_start_pos = 200;
// Leg 3
int servo8_start_pos = 190;
int servo9_start_pos = 265;
// Leg 4
int servo10_start_pos = 200;
int servo11_start_pos = 155;
// Leg 5
int servo12_start_pos = 140;
int servo13_start_pos = 300;
// Leg 6
int servo14_start_pos = 270;
int servo15_start_pos = 140;
