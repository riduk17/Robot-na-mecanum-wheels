#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_8KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor4(4, MOTOR12_8KHZ);
 char a;
void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  motor1.setSpeed(190);     // set the speed to 125/255 125 is minimum
  motor2.setSpeed(190);
  motor3.setSpeed(190);
  motor4.setSpeed(190);
}


void loop() {
  if (Serial.available()) {
    a = (char)Serial.read();
    Serial.write(a);
      if (a == '1') {
        digitalWrite(8, LOW);
        motor1.run(FORWARD);  // turn it on going forward
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
      }
      
      if (a == '2') {
        digitalWrite(8, LOW);
        motor1.run(BACKWARD);  // turn it on going forward
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(FORWARD);
      }
      
      if (a == '3') {
        digitalWrite(8, LOW);
        motor1.run(FORWARD);  // turn it on going forward
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(BACKWARD);
      }
      
      if (a == '4') {
        digitalWrite(8, LOW);
        motor1.run(BACKWARD);  // turn it on going forward
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
      }

      if (a == '7') {
        digitalWrite(8, LOW);
        motor1.run(BACKWARD);  // turn it on going forward
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
      }
      
      if (a == '8') {
        digitalWrite(8, LOW);
        motor1.run(FORWARD);  // turn it on going forward
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
      }
      if ( a == '0') {
        digitalWrite(8, HIGH);
        motor1.run(RELEASE);      // stopped
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
      }
    }
    
  }
