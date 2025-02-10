#include <Arduino.h>
#include <Servo.h>

Servo servo_FR_arm;
Servo servo_BR_arm;
Servo servo_BL_arm;
Servo servo_FL_arm;
Servo servo_FR_paw;
Servo servo_BR_paw;
Servo servo_BL_paw;
Servo servo_FL_paw;

void zero() {
  servo_FR_arm.write(90);
  servo_BR_arm.write(90);
  servo_BL_arm.write(90);
  servo_FL_arm.write(90);

  servo_FR_paw.write(90);
  servo_BR_paw.write(90);
  servo_BL_paw.write(90);
  servo_FL_paw.write(90);
}

void standby() {
  servo_FR_arm.write(120);
  servo_BR_arm.write(60);
  servo_BL_arm.write(120);
  servo_FL_arm.write(60);

  servo_FR_paw.write(20);
  servo_BR_paw.write(160);
  servo_BL_paw.write(20);
  servo_FL_paw.write(160);
}

void walkForward() {
  static const int COUNT = 6;
  static int steps[][8] = {
  //   Arm Angles            Paw Angles
  // FR  BR  BL  FL       FR  BR   BL  FL
  // {120, 60, 120, 60,    40, 140, 40, 140},
  // {160, 60, 90, 60,    40, 140, 40, 140}, // FR and BL leg move forward + paws lowered 
  // {120, 60, 120, 60,    40, 140, 40, 90}, // FR and BL leg move back
  // {120, 90, 120, 30,    40, 140, 40, 140},// BR and FL leg move forward + paws lowered 
  // {120, 60, 120, 60,    90, 140, 40, 140},// BR and FL leg move back
  // {120, 60, 120, 60,    40, 140, 40, 140},

  {120, 60, 120, 60,    20, 160, 20, 160},
  //{120, 60, 120, 60,    20, 110, 20, 160}, // raise br paw
  {120, 100, 120, 60,    20, 160, 20, 160}, // move br leg forward and lower br paw
  //{120, 100, 120, 60,    70, 160, 20, 160}, // raise fr paw
  {160, 100, 120, 60,    20, 160, 20, 160}, // move fr leg forward and lower fr paw
  //{160, 100, 120, 60,    20, 160, 70, 160}, // raise bl paw
  {160, 100, 80, 60,    20, 160, 20, 160}, // move bl leg forward and lower bl paw
  //{160, 100, 80, 60,    20, 160, 20, 110}, // raise fl paw
  {160, 100, 80, 20,    20, 160, 20, 160}, // move fl leg forward and lower fl paw
  {120, 60, 120, 60,    20, 160, 20, 160},
  };

  for(int i = 0; i < COUNT; i++) {
    servo_FR_arm.write(steps[i][0]);
    servo_BR_arm.write(steps[i][1]);
    servo_BL_arm.write(steps[i][2]);
    servo_FL_arm.write(steps[i][3]);

    servo_FR_paw.write(steps[i][4]);
    servo_BR_paw.write(steps[i][5]);
    servo_BL_paw.write(steps[i][6]);
    servo_FL_paw.write(steps[i][7]);
    delay(200);
  }
}

void turnRight() {
  static const int COUNT = 6;
  static int steps[][8] = {
  //   Arm Angles            Paw Angles
  // FR  BR  BL  FL       FR  BR   BL  FL
    {120, 60, 120, 60,    40, 140, 40, 140},

    {60, 60, 120, 60,    40, 140, 40, 140},
    {60, 60, 60, 60,    40, 140, 40, 140},
    
    {60, 0, 60, 60,    40, 140, 40, 140},
    {60, 0, 60, 0,    40, 140, 40, 140},

    {120, 60, 120, 60,    40, 140, 40, 140},
  };

  for(int i = 0; i < COUNT; i++) {
    servo_FR_arm.write(steps[i][0]);
    servo_BR_arm.write(steps[i][1]);
    servo_BL_arm.write(steps[i][2]);
    servo_FL_arm.write(steps[i][3]);

    servo_FR_paw.write(steps[i][4]);
    servo_BR_paw.write(steps[i][5]);
    servo_BL_paw.write(steps[i][6]);
    servo_FL_paw.write(steps[i][7]);
    delay(150);
  }
}

void turnLeft() {
  static const int COUNT = 6;
  static int steps[][8] = {
  //   Arm Angles            Paw Angles
  // FR  BR  BL  FL       FR  BR   BL  FL
    {120, 60, 120, 60,    40, 140, 40, 140},

    {180, 60, 120, 60,    40, 140, 40, 140},
    {180, 60, 180, 60,    40, 140, 40, 140},
    
    {180, 120, 180, 60,    40, 140, 40, 140},
    {180, 120, 180, 120,    40, 140, 40, 140},

    {120, 60, 120, 60,    40, 140, 40, 140},
  };

  for(int i = 0; i < COUNT; i++) {
    servo_FR_arm.write(steps[i][0]);
    servo_BR_arm.write(steps[i][1]);
    servo_BL_arm.write(steps[i][2]);
    servo_FL_arm.write(steps[i][3]);

    servo_FR_paw.write(steps[i][4]);
    servo_BR_paw.write(steps[i][5]);
    servo_BL_paw.write(steps[i][6]);
    servo_FL_paw.write(steps[i][7]);
    delay(150);
  }
}

void setup() {
  // put your setup code here, to run once:
    servo_FR_arm.attach(12);
    servo_BR_arm.attach(13);
    servo_BL_arm.attach(4);
    servo_FL_arm.attach(5);
    servo_FR_paw.attach(14);
    servo_BR_paw.attach(15);
    servo_BL_paw.attach(2);
    servo_FL_paw.attach(16);

    zero();
    delay(500);
    standby();
    delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //walkForward();
  turnRight();
  turnRight();
  turnRight();
  turnRight();
  turnLeft();
  turnLeft();
  turnLeft();
  turnLeft();

  walkForward();
  walkForward();
}
