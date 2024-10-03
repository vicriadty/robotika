#include <L298N.h> //IMPORT LIBRARY MODULE
const int ENA = 6; // motor A (kiri)
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 2;
const int IN4 = 4;
const int ENB = 3;  // motor B (kanan)
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB); 
int time_delay = 1000;
int speed =60;

void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  drive(L298N::MOTOR_A,LOW,HIGH); //MAJU 
  drive(L298N::MOTOR_B,LOW,HIGH);
  delay(2000);
  drive(L298N::MOTOR_A,HIGH,LOW); //MUNDUR
  drive(L298N::MOTOR_B,HIGH,LOW);
  delay(2000);
}

void drive(int motor,int state1,int state2) {
  driver.setup_motor(motor,state1,state2);
  driver.drive_motor(motor,speed); 
}
