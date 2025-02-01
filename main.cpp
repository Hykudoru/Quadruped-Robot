// Board: NodeMCU 1.0 ESP-12E Module
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

void walk() {
  static int steps[][8] = {
    {120, 60, 120, 60,    90, 160, 90, 160}, // FR and BL paws raised
    {160, 60, 90, 60,    20, 160, 20, 160}, // FR and BL leg move forward + paws lowered 
    
    {160, 60, 90, 60,    20, 90, 20, 90}, //BR and FL paws raised
    {120, 60, 120, 60,    20, 90, 20, 90}, // FR and BL leg move back
    {120, 90, 120, 30,    20, 160, 20, 160},// BR and FL leg move forward + paws lowered 
    {120, 60, 120, 60,    20, 160, 20, 160},// BR and FL leg move back
  };

  for(int i = 0; i < 6; i++) {
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
  walk();
}
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

void walk() {
  static int steps[][8] = {
    {120, 60, 120, 60,    90, 160, 90, 160}, // FR and BL paws raised
    {160, 60, 90, 60,    20, 160, 20, 160}, // FR and BL leg move forward + paws lowered 
    
    {160, 60, 90, 60,    20, 90, 20, 90}, //BR and FL paws raised
    {120, 60, 120, 60,    20, 90, 20, 90}, // FR and BL leg move back
    {120, 90, 120, 30,    20, 160, 20, 160},// BR and FL leg move forward + paws lowered 
    {120, 60, 120, 60,    20, 160, 20, 160},// BR and FL leg move back
  };

  for(int i = 0; i < 6; i++) {
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
  walk();
}
