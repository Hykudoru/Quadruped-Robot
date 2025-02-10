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
}

void loop() {
  // put your main code here, to run repeatedly:

}
