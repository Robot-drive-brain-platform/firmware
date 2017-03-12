//By: ASCAS (Angelo S. Casimiro)
//Instructables.com & ASCAS.tk

#include "DualVNH5019MotorShield.h"
DualVNH5019MotorShield md;

//#define LED_PIN       13 // user LED pin

//--------------------------------------------//

char dataIn = 'S'; //Bluetooth stream var
char determinant; //misc variable
char det; //direction
int vel = 0; //Initial velocity

int state = 0; //servo state
int servoPin = 5; //servo connected to digital pin 9
int pulse; //servo pulse for digital write

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  md.init();
  pinMode(ledPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  delay(100);
}

void loop() {

  if (state == 1) {
    flag();
  }
  det = check();

  while (det == 'F')   // F, move forward
  {
    md.setSpeeds(vel, vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'B')   // B, move back
  {
    md.setSpeeds(-vel, -vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'L')   // L, move wheels left
  {
    md.setSpeeds(vel, vel / 4);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'R')   // R, move wheels right
  {
    md.setSpeeds(vel / 4, vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'l')   // l, 360 left
  {
    md.setSpeeds(vel , -vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'r')   // r, 360 right
  {
    md.setSpeeds(-vel , vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'I')   // I, turn right forward
  {
    md.setSpeeds(vel / 2, vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'J')   // J, turn right back
  {
    md.setSpeeds(-vel / 2, -vel);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'G')   // G, turn left forward
  {
    md.setSpeeds(vel, vel / 2);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'H')   // H, turn left back
  {
    md.setSpeeds(-vel, -vel / 2);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  while (det == 'S')   // S, stop
  {
    md.setSpeeds(0, 0);

    if (state == 1) {
      flag();
    }
    det = check();
  }

  //---------------------LED Power------------------//
  while (det == 'X')
  {
    digitalWrite(ledPin, HIGH);

    //if (state == 1) {flag();}
    det = check();
  }

  while (det == 'x')
  {
    digitalWrite(ledPin, LOW);

    //if (state == 1) {flag();}
    det = check();
  }

}


int check()
{ if (Serial.available() > 0) {
    dataIn = Serial.read();
    if (dataIn == 'F') {
      determinant = 'F';
    }
    else if (dataIn == 'B') {
      determinant = 'B';
    } else if (dataIn == 'L') {
      determinant = 'L';
    }
    else if (dataIn == 'R') {
      determinant = 'R';
    }
    else if (dataIn == 'r') {
      determinant = 'r';
    }
    else if (dataIn == 'l') {
      determinant = 'l';
    }
    else if (dataIn == 'I') {
      determinant = 'I';
    }
    else if (dataIn == 'J') {
      determinant = 'J';
    } 
    else if (dataIn == 'G') {
      determinant = 'G';
    }
    else if (dataIn == 'H') {
      determinant = 'H';
    } 
    else if (dataIn == 'S') {
      determinant = 'S';
    }
    else if (dataIn == '0') {
      vel = 400;
    } 
    else if (dataIn == '1') {
      vel = 380;
    }
    else if (dataIn == '2') {
      vel = 340;
    } 
    else if (dataIn == '3') {
      vel = 320;
    }
    else if (dataIn == '4') {
      vel = 280;
    } 
    else if (dataIn == '5') {
      vel = 240;
    }
    else if (dataIn == '6') {
      vel = 200;
    } 
    else if (dataIn == '7') {
      vel = 160;
    }
    else if (dataIn == '8') {
      vel = 120;
    } 
    else if (dataIn == '9') {
      vel = 80;
    }
    else if (dataIn == 'q') {
      vel = 40;
    } 
    else if (dataIn == 'U') {
      state = 1;
    }
    else if (dataIn == 'u') {
      state = 0;
    } 
    else if (dataIn == 'W') {
      determinant = 'W';
    }
    else if (dataIn == 'w') {
      determinant = 'w';
    }
    else if (dataIn == 'X') {
      determinant = 'X';
    }
    else if (dataIn == 'x') {
      determinant = 'x';
    }
  }
  return determinant;
}

void flag()
{
  for (pulse = 500 ; pulse <= 2500; pulse += 10) {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(servoPin, LOW);
    delay(1);
  }
  delay(10);
  for (pulse = 2500 ; pulse >= 500; pulse -= 10) {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(servoPin, LOW);
    delay(1);
  }

  state = 0;
}

