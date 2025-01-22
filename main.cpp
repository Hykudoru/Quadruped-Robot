// Board: NodeMCU 1.0 ESP-12E Module
#include <Servo.h>  //Import servo library
Servo servo_FR_arm;
Servo servo_BR_arm;
Servo servo_BL_arm;
Servo servo_FL_arm;
Servo servo_FR_paw;
Servo servo_BR_paw;
Servo servo_BL_paw;
Servo servo_FL_paw;

Servo limbs[] = {
  servo_FR_arm,
  servo_BR_arm,
  servo_BL_arm,
  servo_FL_arm,
  servo_FR_paw,
  servo_BR_paw,
  servo_BL_paw,
  servo_FL_paw,
};

void idle() {
  static int idle[1][9] = { 
    {155, 115, 155, 115, 20, 160, 20, 160, 1000} // Stance
  };

   for (size_t i = 0; i < 1; i++)
   {
     servo_FR_arm.write(idle[i][0]);
     servo_BR_arm.write(idle[i][1]);
     servo_BL_arm.write(idle[i][2]);
     servo_FL_arm.write(idle[i][3]);
     servo_FR_paw.write(idle[i][4]);
     servo_BR_paw.write(idle[i][5]);
     servo_BL_paw.write(idle[i][6]);
     servo_FL_paw.write(idle[i][7]);
     delay(idle[i][8]);
   }
}

void walk() {
  static int walk[][9] = {
    {155, 115, 155, 115,   50, 160, 50, 160,    100}, // raise forward-right and back-left paw
    {180, 115, 135, 115,   50, 160, 50, 160,   100}, // move forward-right and back-left leg forward
    {180, 115, 135, 115,   20, 160, 20, 160,   100}, // lower forward-right and back-left paw
    {180, 115, 135, 115,   20, 140, 20, 140,   100}, // raise forward-left and back-right paw
    {135, 115, 155, 115,   20, 160, 20, 160,   100}, // move forward-right and back-left legs backward
    {135, 155, 155, 90,    20, 140, 20, 140,   100}, // move forward-left and back-right legs forward 
    {135, 155, 155, 90,    20, 160, 20, 160,   100}, // lower forward-left and back-right paw
    {135, 115, 155, 115,   20, 160, 20, 160,   100}, // 
  };

  for (size_t i = 0; i < 8; i++)
  {
     servo_FR_arm.write(walk[i][0]);
     servo_BR_arm.write(walk[i][1]);
     servo_BL_arm.write(walk[i][2]);
     servo_FL_arm.write(walk[i][3]);
     servo_FR_paw.write(walk[i][4]);
     servo_BR_paw.write(walk[i][5]);
     servo_BL_paw.write(walk[i][6]);
     servo_FL_paw.write(walk[i][7]);
     delay(walk[i][8]);
  }
}

void zero() {
  servo_FR_arm.write(135);
  servo_BR_arm.write(135);
  servo_BL_arm.write(135);
  servo_FL_arm.write(135);
  servo_FR_paw.write(90);
  servo_BR_paw.write(90);
  servo_BL_paw.write(90);
  servo_FL_paw.write(90);
}

void setup() { //Initialize the GPIO pin number of each servo
  servo_FR_arm.attach(12);
  servo_BR_arm.attach(13);
  servo_BL_arm.attach(4);
  servo_FL_arm.attach(5);
  servo_FR_paw.attach(14);
  servo_BR_paw.attach(15);
  servo_BL_paw.attach(2);
  servo_FL_paw.attach(16);
  
  zero();
  delay(1000);
  idle();
}

void loop() {
   walk();

   delay(10000);
}